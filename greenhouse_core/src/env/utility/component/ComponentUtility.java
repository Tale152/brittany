package utility.component;

import java.util.List;
import java.util.stream.Collectors;

/**
 * ComponentUtility is a class used to handle easily reseaches about
 * components, without having to implement them more than once.
 */
public class ComponentUtility {
    
    /**
	 * Utility method used to seach in a list of components, components of a specific
     * category that have actions, which can be called actuators.
	 * 
	 * @param components the list of components used to seach for actuators 
     *                   of a specific category.
	 * @param category   the category of the actuators that are wanted to be retrieved.
	 * @return the list of actuators of a specific category.
	 */
    public static List<Component> getActuatorsByCategory(final List<Component> components, final String category) {
		return components.stream().filter(c -> c.getCategory().equals(category))
				.filter(c -> !c.getActions().isEmpty()).collect(Collectors.toList());
	}

    /**
	 * Utility method used to retrieve from a list of components only the components of a specific
	 * category.
	 * 
     * @param components the list of components used to search for components of a specific category.
	 * @param category   the cateogry of the components that are wanted to be retrieved.
	 * @return the list of components that have a specific category.
	 */
	public static List<Component> getComponentsByCategory(final List<Component> components, final String category) {
		return components.stream().filter(c -> c.getCategory().equals(category)).filter(c -> !c.getProperties().isEmpty()).collect(Collectors.toList());
	}

}
