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

	}

	private void getThingDescriptor(final String url) {
		//TODO
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
					Map<String, ConsumedThingProperty<Object>> moduleProperties = null;
					Map<String, ConsumedThingAction<Object, Object>> moduleActions = null;

					if (thingDescriptor.has("properties")) {
						JsonObject properties = thingDescriptor.getAsJsonObject("properties");
						moduleProperties = getPropertiesByName(consumedThing, getNamesByCategory(properties, category));
					}
					if (thingDescriptor.has("actions")) {
						JsonObject actions = thingDescriptor.getAsJsonObject("actions");
						moduleActions = getActionsByName(consumedThing, getNamesByCategory(actions, category));
					}
					if (jsonModule.has("components")) {
						JsonArray components = jsonModule.getAsJsonArray("components");
						for (JsonElement component : components) {
							ComponentBuilder componentBuilder = ComponentBuilder.create(edgeIp, component.getAsString(), category);
							if (moduleProperties != null) {
								componentBuilder.addProperties(moduleProperties);
							}
							if (moduleActions != null) {
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

	private List<String> getNamesByCategory(final JsonObject td, final String category) {
		List<String> names = new ArrayList<>();
		Set<Map.Entry<String, JsonElement>> entries = td.entrySet();
		for (Map.Entry<String, JsonElement> entry : entries) {
			JsonObject property = td.getAsJsonObject(entry.getKey());
			if (property.has("module") && property.get("module").getAsString().equals(category)) {
				names.add(entry.getKey());
			}
		}
		return names;
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
