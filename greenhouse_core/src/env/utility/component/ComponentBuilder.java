package utility.component;

import java.util.HashMap;
import java.util.Map;

import city.sane.wot.thing.action.ConsumedThingAction;
import city.sane.wot.thing.property.ConsumedThingProperty;

public class ComponentBuilder {
	private final String edgeIp;
	private final String id;
	private final String category;
	private Map<String, ConsumedThingProperty<Object>> properties;
	private Map<String, ConsumedThingAction<Object, Object>> actions;

	private ComponentBuilder(final String edgeIp, final String id, final String category) {
		this.edgeIp = edgeIp;
		this.id = id;
		this.category = category;
		this.properties = new HashMap<>();
		this.actions = new HashMap<>();
	}

	public static ComponentBuilder create(final String edgeIp, final String id, final String category) {
		return new ComponentBuilder(edgeIp, id, category);
	}

	public ComponentBuilder addProperties(final Map<String, ConsumedThingProperty<Object>> properties) {
		this.properties = properties;
		return this;
	}

	public ComponentBuilder addActions(final Map<String, ConsumedThingAction<Object, Object>> actions) {
		this.actions = actions;
		return this;
	}

	public Component build() {
		return new Component(edgeIp, id, category, properties, actions);
	}
	
}
