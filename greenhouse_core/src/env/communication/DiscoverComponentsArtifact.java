// CArtAgO artifact code for project greenhouse_core

package communication;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.typesafe.config.Config;
import com.typesafe.config.ConfigFactory;

import cartago.*;
import city.sane.wot.DefaultWot;
import city.sane.wot.Wot;
import city.sane.wot.WotException;
import city.sane.wot.thing.ConsumedThing;
import city.sane.wot.thing.Thing;
import city.sane.wot.thing.action.ConsumedThingAction;
import city.sane.wot.thing.property.ConsumedThingProperty;
import utility.component.Component;
import utility.component.ComponentBuilder;

public class DiscoverComponentsArtifact extends Artifact {

	private List<Component> components;
	private Wot wot;

	void init() {
		this.components = new ArrayList<>();

		Config config = ConfigFactory.parseString(
				"wot.servient.client-factories = [\"city.sane.wot.binding.http.HttpProtocolClientFactory\"]");
		config = config.withFallback(ConfigFactory.load());
		try {
			this.wot = DefaultWot.clientOnly(config);
		} catch (WotException e1) {
			e1.printStackTrace();
		}
		getThingDescriptorByFile();
	}

	@OPERATION
	void discoverComponents() {
		// i don't know how to broadcast a message but I assume a will receive urls of
		// the proper devices

		//for test purposes
		getThingDescriptorByFile();
		System.out.println("UPDATED COMPONENTS!");
		System.out.println(this.components);
		defineObsProperty("components", this.components);
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
		Thing thing = Thing.fromJson(thingDescriptor.toString());
		ConsumedThing consumedThing = wot.consume(thing);
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
								Map<String, ConsumedThingProperty<Object>> moduleProperties = getPropertiesByName(consumedThing,getNamesByCategory(properties, category, componentId));
								componentBuilder.addProperties(moduleProperties);
							}
							if (thingDescriptor.has("actions")) {
								JsonObject actions = thingDescriptor.getAsJsonObject("actions");
								Map<String, ConsumedThingAction<Object, Object>> moduleActions = getActionsByName(consumedThing, getNamesByCategory(actions, category, componentId));
								componentBuilder.addActions(moduleActions);
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

	private Map<String, ConsumedThingProperty<Object>> getPropertiesByName(final ConsumedThing consumedThing, final List<String> propertiesNames) {
		Map<String, ConsumedThingProperty<Object>> properties = new HashMap<>();
		for (String name : propertiesNames) {
			properties.put(name, consumedThing.getProperty(name));
		}
		return properties;
	}

	private Map<String, ConsumedThingAction<Object, Object>> getActionsByName(
			final ConsumedThing consumedThing, final List<String> actionsNames) {
				Map<String, ConsumedThingAction<Object, Object>> actions = new HashMap<>();
				for (String name : actionsNames) {
					actions.put(name, consumedThing.getAction(name));
				}
				return actions;
	}

}
