package utility;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

import com.google.gson.JsonElement;
import com.google.gson.JsonObject;

import city.sane.wot.thing.ConsumedThing;

import utility.component.Component;

/**
 * ThingDescriptorUtility is an utility class used to provide
 * methods in order to handle easily the thing descriptor.
 */
public class ThingDescriptorUtility {

	/**
	 * 
	 * 
	 * @param thingDescriptors
	 * @param id
	 * @return
	 */
	public static Optional<ConsumedThing> getThingDescriptor(final List<ConsumedThing> thingDescriptors, final String id) {
		return thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
	}

	/**
	 * 
	 * 
	 * @param td
	 * @param category
	 * @param componentId
	 * @return
	 */
	public static List<String> getNamesByCategory(final JsonObject td, final String category, final String componentId) {
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
