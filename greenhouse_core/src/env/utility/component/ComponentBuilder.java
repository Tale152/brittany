package utility.component;

import java.util.ArrayList;
import java.util.List;

public class ComponentBuilder {
	private final String edgeIp;
	private final String id;
	private final String category;
	private List<String> properties;
	private List<String> actions;

	private ComponentBuilder(final String edgeIp, final String id, final String category) {
		this.edgeIp = edgeIp;
		this.id = id;
		this.category = category;
		this.properties = new ArrayList<>();
		this.actions = new ArrayList<>();
	}

	public static ComponentBuilder create(final String edgeIp, final String id, final String category) {
		return new ComponentBuilder(edgeIp, id, category);
	}

	public ComponentBuilder addProperties(final List<String> properties) {
		this.properties = properties;
		return this;
	}

	public ComponentBuilder addActions(final List<String> actions) {
		this.actions = actions;
		return this;
	}

	public Component build() {
		return new Component(edgeIp, id, category, properties, actions);
	}
	
}
