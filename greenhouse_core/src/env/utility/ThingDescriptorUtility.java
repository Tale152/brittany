package utility;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;
import city.sane.wot.thing.ConsumedThing;

import utility.component.Component;

public class ThingDescriptorUtility {
    
    public static List<Component> getActuatorsByCategory(final List<Component> components, final String category) {
		return components.stream().filter(c -> c.getCategory().equals(category))
				.filter(c -> !c.getActions().isEmpty()).collect(Collectors.toList());
	}

	public static Optional<ConsumedThing> getThingDescriptor(final List<ConsumedThing> thingDescriptors, final String id) {
		return thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
	}
}
