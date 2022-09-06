/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// CArtAgO artifact code for project greenhouse_core

package communication;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.typesafe.config.Config;
import com.typesafe.config.ConfigFactory;

import cartago.*;
import city.sane.wot.DefaultWot;
import city.sane.wot.Wot;
import city.sane.wot.WotException;
import city.sane.wot.thing.ConsumedThing;
import city.sane.wot.thing.Thing;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import utility.component.Component;
import utility.component.ComponentBuilder;
import utility.ThingDescriptorUtility;

/**
 * DiscoverComponentArtifact is an Artifcat that is used to broadcast an HTTP
 * request locally in order to detect all the edges that are part of the
 * greenhouse.
 * It is used to find the components and the thing descriptors that are used
 * to perform action and check properties of the components inside the
 * greenhouse.
 */
public class DiscoverComponentsArtifact extends Artifact {

	private final static long TICK_TIME = 100;

	private OkHttpClient client;
	private List<Component> components;
	private List<ConsumedThing> thingDescriptors;
	private Wot wot;

	void init() {
		this.client = new OkHttpClient();
		configWot();
	}

	/**
	 * Utility method used for the configuration of the Wot,
	 * used to handle the thing descriptor.
	 */
	private void configWot() {
		Config config = ConfigFactory.parseString(
				"wot.servient.client-factories = [\"city.sane.wot.binding.http.HttpProtocolClientFactory\"]");
		config = config.withFallback(ConfigFactory.load());
		try {
			this.wot = DefaultWot.clientOnly(config);
		} catch (WotException e1) {
			e1.printStackTrace();
		}
	}

	/**
	 * Operation used send an HTTP request in order to find all the edges connected
	 * that are part of the greenhouse.
	 */
	@OPERATION
	void discoverComponents() {
		//initialization due to avoid to try to communicate with disconnected components
		this.components = new ArrayList<>();
		this.thingDescriptors = new ArrayList<>();
		//calling asynchronous operation
		execInternalOp("broadcastRequest");
	}

	/**
	 * This internal operation is used to run an asynchronous operation,
	 * which it is usually for a long term operation.
	 * This internal operation is used to cicle on all the ip adresses
	 * in order to find all the edges connected to the greenhouse, and 
	 * it requires some time.
	 * 
	 * Even though it runs asynchronously, it is necessary to call
	 * await time, which stops the executing operation and makes
	 * it possible to commit the observable states.
	 */
	@INTERNAL_OPERATION
	void broadcastRequest() {
		for (int i = 1; i <= 255; i++) {
			getThingDescriptor("http://" + System.getenv("SUBNET_IP") + "." + i);
			await_time(TICK_TIME);
		}
		defineObsProperty("wait");
	}

	/**
	 * Utility method used to send an HTTP request to a specific url,
	 * looking for one that returns the thing descriptor.
	 * 
	 * @param url the url to which the thing descriptor is requestes.
	 */
	private void getThingDescriptor(final String url) {
		Request request = new Request.Builder().url(url).build();
		try (Response response = client.newCall(request).execute()) {
			if (response.isSuccessful()) {
				System.out.println("Successful edge response at url " + url);
				JsonObject thingDescriptor = JsonParser.parseString(response.body().string()).getAsJsonObject();
				updateComponents(thingDescriptor); //if found, update components
				//update components and thing descriptors
				defineObsProperty("components", this.components);
				defineObsProperty("thingDescriptors", this.thingDescriptors);
			}
		} catch (IOException e) {
			System.err.println("Impossible to contact edge at url " + url);
		}
	}

	/**
	 * Utility method used to find inside the thing descriptor its modules,
	 * which is the edge that had information about the sensors and
	 * the actuators that can be contacted in the greenhouse.
	 * 
	 * @param thingDescriptor the jsonObject that has all the information
	 *                        about the modules in the greenhouse.
	 */
	private void updateComponents(final JsonObject thingDescriptor) {
		Thing thing = Thing.fromJson(thingDescriptor.toString());
		ConsumedThing consumedThing = wot.consume(thing);
		this.thingDescriptors.add(consumedThing);
		String edgeIp = consumedThing.getId();
		if (thingDescriptor.has("modules")) {
			JsonArray modules = thingDescriptor.getAsJsonArray("modules");
			for (JsonElement module : modules) {
				JsonObject jsonModule = module.getAsJsonObject();
				handleModule(edgeIp, thingDescriptor, jsonModule);
			}
		}
	}

	/**
	 * Utility method used to extract from each module, all the components that are
	 * connected to it.
	 * Each component can have properties and actions.
	 * 
	 * @param edgeIp          the ip of the module that contains the components.
	 * @param thingDescriptor the whole thing descriptor returned by the HTTP
	 *                        request.
	 * @param jsonModule      the thing descriptor of a specific module.
	 */
	private void handleModule(final String edgeIp, final JsonObject thingDescriptor, final JsonObject jsonModule) {
		if (jsonModule.has("module")) {
			String category = jsonModule.get("module").getAsString();
			if (jsonModule.has("components")) {
				JsonArray components = jsonModule.getAsJsonArray("components");
				for (JsonElement component : components) {
					String componentId = component.getAsString();
					ComponentBuilder componentBuilder = ComponentBuilder.create(edgeIp, componentId, category);
					if (thingDescriptor.has("properties")) {
						JsonObject properties = thingDescriptor.getAsJsonObject("properties");
						componentBuilder.addProperties(ThingDescriptorUtility.getNamesByCategory(properties, category, componentId));
					}
					if (thingDescriptor.has("actions")) {
						JsonObject actions = thingDescriptor.getAsJsonObject("actions");
						componentBuilder.addActions(ThingDescriptorUtility.getNamesByCategory(actions, category, componentId));
					}
					Component foundComponent = componentBuilder.build();
					addComponentIfNotContained(foundComponent);
				}
			}
		}
	}

	/**
	 * Utility method used to add the new component in a list only if it is not
	 * already present.
	 * This is made for security sake, but it should not occur because the list of
	 * components is emptied each time a new discovery is made.
	 * 
	 * @param foundComponent the component created.
	 */
	private void addComponentIfNotContained(final Component foundComponent) {
		if (!this.components.contains(foundComponent)) {
			this.components.add(foundComponent);
		}
	}

}
