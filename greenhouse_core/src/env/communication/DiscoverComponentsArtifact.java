// CArtAgO artifact code for project greenhouse_core

package communication;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import com.google.gson.Gson;
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

public class DiscoverComponentsArtifact extends Artifact {
	private static final String URL = "http://192.168.25.1";

	private OkHttpClient client;

	private List<Component> components;
	private List<ConsumedThing> thingDescriptors;
	private Wot wot;

	void init() {
		this.client = new OkHttpClient();
		this.components = new ArrayList<>();

		Config config = ConfigFactory.parseString(
				"wot.servient.client-factories = [\"city.sane.wot.binding.http.HttpProtocolClientFactory\"]");
		config = config.withFallback(ConfigFactory.load());
		try {
			this.wot = DefaultWot.clientOnly(config);
		} catch (WotException e1) {
			e1.printStackTrace();
		}
		getThingDescriptor();
	}

	@OPERATION
	void discoverComponents() {
		// i don't know how to broadcast a message but I assume a will receive urls of
		// the proper devices

		//for test purposes
		getThingDescriptor();
		System.out.println("UPDATED COMPONENTS!");
		defineObsProperty("components", this.components);
		defineObsProperty("thingDescriptors", this.thingDescriptors);
	}

	private void getThingDescriptor() {
		Request request = new Request.Builder().url(URL).build();
		try (Response response = client.newCall(request).execute()) {
			if (!response.isSuccessful()) {
				throw new IOException("Unexpected code " + response);
			}
			JsonObject thingDescriptor = JsonParser.parseString(response.body().string()).getAsJsonObject();
			updateComponents(thingDescriptor);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void getThingDescriptorByFile() {
		Gson gson = new Gson();
		try {
			BufferedReader reader = new BufferedReader(new FileReader("td.json"));
			JsonObject thingDescriptor = gson.fromJson(reader, JsonObject.class);
			updateComponents(thingDescriptor);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void updateComponents(final JsonObject thingDescriptor) {
		this.thingDescriptors = new ArrayList<>();

		Thing thing = Thing.fromJson(thingDescriptor.toString());
		ConsumedThing consumedThing = wot.consume(thing);
		this.thingDescriptors.add(consumedThing);
		String edgeIp = consumedThing.getId();
		if (thingDescriptor.has("modules")) {
			JsonArray modules = thingDescriptor.getAsJsonArray("modules");
			for (JsonElement module : modules) {
				JsonObject jsonModule = module.getAsJsonObject();
				if (jsonModule.has("module")) {
					String category = jsonModule.get("module").getAsString();
					if (jsonModule.has("components")) {
						JsonArray components = jsonModule.getAsJsonArray("components");
						for (JsonElement component : components) {
							String componentId = component.getAsString();
							ComponentBuilder componentBuilder = ComponentBuilder.create(edgeIp, componentId, category);

							if (thingDescriptor.has("properties")) {
								JsonObject properties = thingDescriptor.getAsJsonObject("properties");
								componentBuilder.addProperties(getNamesByCategory(properties, category, componentId));
							}
							if (thingDescriptor.has("actions")) {
								JsonObject actions = thingDescriptor.getAsJsonObject("actions");
								componentBuilder.addActions(getNamesByCategory(actions, category, componentId));
							}
							Component foundComponent = componentBuilder.build();
							if (!this.components.contains(foundComponent)){
								this.components.add(foundComponent);
							}	
						}
					}
				}
			}

		}
	}

	private List<String> getNamesByCategory(final JsonObject td, final String category, final String componentId) {
		List<String> names = new ArrayList<>();
		Set<Map.Entry<String, JsonElement>> entries = td.entrySet();
		for (Map.Entry<String, JsonElement> entry : entries) {
			JsonObject property = td.getAsJsonObject(entry.getKey());
			if (property.has("module") && property.get("module").getAsString().equals(category)) {
				names.add(entry.getKey());
			}
		}
		return names.stream().filter(n -> n.substring(n.lastIndexOf("-") + 1).equals(componentId)).collect(Collectors.toList());
	}

}
