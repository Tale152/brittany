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
	 * Utility method used to find in a list of thing descriptors a specific
	 * thing descriptor by its identifier.
	 * 
	 * @param thingDescriptors the list of thing descriptors.
	 * @param id 			   the id of the thing descriptor wanted.
	 * @return an optional of the thing descriptor with the specified id if found,
	 * and optional of empty otherwise.
	 */
	public static Optional<ConsumedThing> getThingDescriptor(final List<ConsumedThing> thingDescriptors, final String id) {
		return thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
	}

	/**
	 * Utility method used to get a list of actions and/or properties names from
	 * the thing descriptor of a specific component, of a specific category.
	 * 
	 * @param td 		  the thing descriptor that contains the actions or the properties.
	 * @param category	  the category of the action or properties wanted.
	 * @param componentId the id of the component of which the names of properties or
	 * 					  actions are wanted.
	 * @return a list of names of the action or the properties of a specific component, based
	 * on its category.
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
