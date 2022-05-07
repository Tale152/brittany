package utility.component;

import java.util.List;
import java.util.Optional;

/**
 * Component class used to represent a Component in the greenhouse,
 * including the edge ip it is connected to and all the properties and
 * action names that have been retrieved from the thing descriptor.
 */
public class Component {

	private final String edgeIp;
	private final String id;
	private final String category;
	private final List<String> properties;
	private final List<String> actions;

	/**
	 * Component constructor, used to give all the information that
	 * a Component needs.
	 * 
	 * @param edgeIp     the ip of the edge where the component is connected.
	 * @param id         the id of the component.
	 * @param category   the category of the component.
	 * @param properties the list of the properties' names that the component have.
	 * @param actions    the list of the actions' names tha the component can perform.
	 */
	protected Component(final String edgeIp, final String id, final String category,
			final List<String> properties, final List<String> actions) {
		this.edgeIp = edgeIp;
		this.id = id;
		this.category = category;
		this.properties = properties;
		this.actions = actions;
	}

	/**
	 * A component is always connected to an edge, which has an ip.
	 * This method returns the edge's ip where the component is connected to.
	 * 
	 * @return the edge's ip that is resposible of the component.
	 */
	public String getEdgeIp() {
		return edgeIp;
	}

	/**
	 * A component has an identificator that is unique for the edge 
	 * it is connected to.
	 * 
	 * @return the unique id of the component.
	 */
	public String getId() {
		return id;
	}

	/**
	 * A component has a category it falls into, which defines the kind
	 * of sensor of actuator it is.
	 * 
	 * @return the category of the component.
	 */
	public String getCategory() {
		return category;
	}

	/**
	 * A component has a list of names of the properties it can access,
	 * which are extracted from the thing descriptor of the edge it
	 * is connected to.
	 * 
	 * @return the list of names of the properties that the component can
	 * access.
	 */
	public List<String> getProperties() {
		return properties;
	}

	/**
	 * Method used to extract a property using a known 
	 * part of the name of the property wanted.
	 * 
	 * @param subString the part of the property name known.
	 * @return the complete name of the property found 
	 * starting from the substring provided.
	 */
	public Optional<String> getPropertyBySubString(final String subString) {
		return this.properties.stream().filter(s -> s.contains(subString)).findFirst();
	}

	/**
	 * A component has a list of names of the action it can perform,
	 * which are extracted from the thing descriptor of the edge it
	 * is connected to.
	 * 
	 * @return the list of names of the actions that the component can
	 * perform.
	 */
	public List<String> getActions() {
		return actions;
	}

	/**
	 * Method used to extract an action using a known 
	 * part of the name of the action wanted.
	 * 
	 * @param subString the part of the action name known.
	 * @return the complete name of the action found 
	 * starting from the substring provided.
	 */
	public Optional<String> getActionBySubString(final String subString) {
		return this.actions.stream().filter(s -> s.contains(subString)).findFirst();
	}

	@Override
	public String toString() {
		return "Component [actions=" + actions + ", category=" + category + ", edgeIp=" + edgeIp + ", id=" + id
				+ ", properties=" + properties + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((actions == null) ? 0 : actions.hashCode());
		result = prime * result + ((category == null) ? 0 : category.hashCode());
		result = prime * result + ((edgeIp == null) ? 0 : edgeIp.hashCode());
		result = prime * result + ((id == null) ? 0 : id.hashCode());
		result = prime * result + ((properties == null) ? 0 : properties.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Component other = (Component) obj;
		if (actions == null) {
			if (other.actions != null)
				return false;
		} else if (!actions.equals(other.actions))
			return false;
		if (category == null) {
			if (other.category != null)
				return false;
		} else if (!category.equals(other.category))
			return false;
		if (edgeIp == null) {
			if (other.edgeIp != null)
				return false;
		} else if (!edgeIp.equals(other.edgeIp))
			return false;
		if (id == null) {
			if (other.id != null)
				return false;
		} else if (!id.equals(other.id))
			return false;
		if (properties == null) {
			if (other.properties != null)
				return false;
		} else if (!properties.equals(other.properties))
			return false;
		return true;
	}

}
