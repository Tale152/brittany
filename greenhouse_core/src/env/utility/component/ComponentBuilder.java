package utility.component;

import java.util.ArrayList;
import java.util.List;

/**
 * ComponentBuilder applies the Builder pattern in order to 
 * create a [[utility.component.Component]] in an easier way.
 */
public class ComponentBuilder {
	private final String edgeIp;
	private final String id;
	private final String category;
	private List<String> properties;
	private List<String> actions;

	/**
	 * Private ComponentBuilder constructor, used to create a ComponentBuilder internally,
	 * which contains part of the information used to create a Component.
	 * 
	 * @param edgeIp     the ip of the edge where the component is connected.
	 * @param id         the id of the component.
	 * @param category   the category of the component.
	 */
	private ComponentBuilder(final String edgeIp, final String id, final String category) {
		this.edgeIp = edgeIp;
		this.id = id;
		this.category = category;
		this.properties = new ArrayList<>();
		this.actions = new ArrayList<>();
	}

	/**
	 * Method used to create a ComponentBuilder, with the basic information
	 * that a Component needs.
	 * 
	 * @param edgeIp     the ip of the edge where the component is connected.
	 * @param id         the id of the component.
	 * @param category   the category of the component.
	 * @return a ComponentBuilder contain the information passed and that can be enriched
	 * with more information if necessary.
	 */
	public static ComponentBuilder create(final String edgeIp, final String id, final String category) {
		return new ComponentBuilder(edgeIp, id, category);
	}

	/**
	 * Method used if necessery to add to the ComponentBuilder 
	 * a list of names of the properties that the component has
	 * access to.
	 * 
	 * @param properties list of the names of the properties of the component.
	 * @return a ComponentBuilder that can be enriched with more information
	 * if necessary.
	 */
	public ComponentBuilder addProperties(final List<String> properties) {
		this.properties = properties;
		return this;
	}

	/**
	 * Method used if necessary to add to the ComponentBuilder
	 * a list of names of the actions that the component can
	 * perform.
	 * 
	 * @param actions list of the names of the actions of the component.
	 * @return a ComponentBuilder that can be enriched with more information
	 * if necessary.
	 */
	public ComponentBuilder addActions(final List<String> actions) {
		this.actions = actions;
		return this;
	}

	/**
	 * Method that finalize the creation of a Component, once all the information
	 * needed are added.
	 * 
	 * @return the component created with all the information contained in the 
	 * ComponentBuilder.
	 */
	public Component build() {
		return new Component(edgeIp, id, category, properties, actions);
	}
	
}
