package utility.component;

import java.util.Map;

import city.sane.wot.thing.action.ConsumedThingAction;
import city.sane.wot.thing.property.ConsumedThingProperty;

public class Component {
	private final String edgeIp;
	private final String id;
	private final String category;
	private final Map<String, ConsumedThingProperty<Object>> properties;
	private final Map<String, ConsumedThingAction<Object, Object>> actions;

	protected Component(final String edgeIp, final String id, final String category,
			final Map<String, ConsumedThingProperty<Object>> properties,
			final Map<String, ConsumedThingAction<Object, Object>> actions) {
		this.edgeIp = edgeIp;
		this.id = id;
		this.category = category;
		this.properties = properties;
		this.actions = actions;
	}

	public String getEdgeIp() {
		return edgeIp;
	}

	public String getId() {
		return id;
	}

	public String getCategory() {
		return category;
	}

	public Map<String, ConsumedThingProperty<Object>> getProperties() {
		return properties;
	}

	public Map<String, ConsumedThingAction<Object, Object>> getActions() {
		return actions;
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
