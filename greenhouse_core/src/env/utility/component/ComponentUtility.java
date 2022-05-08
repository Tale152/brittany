package utility.component;

import java.util.List;
import java.util.stream.Collectors;

public class ComponentUtility {
    
    /**
	 * 
	 * 
	 * @param components
	 * @param category
	 * @return
	 */
    public static List<Component> getActuatorsByCategory(final List<Component> components, final String category) {
		return components.stream().filter(c -> c.getCategory().equals(category))
				.filter(c -> !c.getActions().isEmpty()).collect(Collectors.toList());
	}

    /**
	 * Utility method used to retrieve from a list of components only the components of a specific
	 * category.
	 * 
     * @param components 
	 * @param category the cateogry of the components that are wanted to be retrieved.
	 * @return the list of components that have a specific category.
	 */
	public static List<Component> getComponentsByCategory(final List<Component> components, final String category) {
		return components.stream().filter(c -> c.getCategory().equals(category)).filter(c -> !c.getProperties().isEmpty()).collect(Collectors.toList());
	}
}
