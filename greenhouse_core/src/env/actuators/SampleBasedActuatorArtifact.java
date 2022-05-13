package actuators;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.ThingDescriptorUtility;
import utility.component.Component;
import utility.component.ComponentUtility;
import utility.sample.Sample;
import utility.setting.RangeSetting;

/**
 * SampleBasedActuatorArtifact is an Artifact that is used to send a message to an
 * actuator to handle when the current sample registered is bigger or lower 
 * than the setting of a specific component category.
 */
public class SampleBasedActuatorArtifact extends Artifact {

	private List<Component> components;
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.components = new ArrayList<>();
		this.thingDescriptors = new ArrayList<>();
	}

	/**
	 * Operation used to set up the list of components when they are retrieved, which 
	 * are the components that the greenhouse can handle.
	 * 
	 * @param components the list of [[utility.component.Component]] found.
	 */
	@OPERATION
	void setupComponents(final List<Component> components) {
		this.components = components;
	}

	/**
	 * Operation used to set up the list of thing descriptors once they are retrieved,
	 * which defines the action and properties of a component.
	 * 
	 * @param thingDescriptors list of the thing descriptors found.
	 */
	@OPERATION
	void setupTds(final List<ConsumedThing> thingDescriptors) {
		this.thingDescriptors = thingDescriptors;
	}

	/**
	 * Operation used to check the current sample and to perform
	 * a different operation if it is bigger or lower that the settings
	 * of a specific category of device.
	 * 
	 * @param outOfRangeSample the sample is out of range base on the settings.
	 * @param setting          the setting of the specific category of the sample.
	 */
	@OPERATION
	void actuate(final Sample outOfRangeSample, final RangeSetting setting) {
		int currentValue = outOfRangeSample.getValue();
		switch (outOfRangeSample.getCategory()) {
			case "temperature":
				if (currentValue < setting.getMin()) {
					System.out.println("Current temperature " + currentValue + " Min value " + setting.getMin());
					switchActuatorAction("temperature", "heatOn", "coolOff");
				} else if (currentValue > setting.getMax()) {
					System.out.println("Current temperature " + currentValue + " Max value " + setting.getMax());
					switchActuatorAction("temperature", "coolOn", "heatOff");
				} else {
					throw new IllegalStateException("The value must be lower than min or higher than max");
				};
				break;
			case "airHumidity":
				if (currentValue < setting.getMin()) {
					System.out.println("Current humidity " + currentValue + " Min value " + setting.getMin());
					switchActuatorAction("airHumidity", "humidifyOn", "dehumidifyOff");
				} else if (currentValue > setting.getMax()) {
					System.out.println("Current humididty " + currentValue + " Max value " + setting.getMax());
					switchActuatorAction("airHumidity", "dehumidifyOn", "humidifyOff");
				} else {
					throw new IllegalStateException("The value must be lower than min or higher than max");
				};
				break;
			}
	}

	/**
	 * Method used to perform an action based on the action present on the thing descriptors of components
	 * that are in a specific category.
	 * 
	 * @param category      the category of the component that registered an out of range sample.
	 * @param turnOnAction  the action that needs to be turned on.
	 * @param turnOffAction the action that needs to be turned off.
	 */
	private void switchActuatorAction(final String category, final String turnOnAction, final String turnOffAction) {
		List<Component> components = ComponentUtility.getActuatorsByCategory(this.components, category);
		for (Component component : components) {
			//search for the specific action in the td list for a specific edge
			Optional<ConsumedThing> td = ThingDescriptorUtility.getThingDescriptor(this.thingDescriptors, component.getEdgeIp());
			if (td.isPresent()) {
				if (component.getActionBySubString(turnOnAction).isPresent()) {
					performActuatorAction(component, td, turnOnAction);
				}
				if (component.getActionBySubString(turnOffAction).isPresent()) {
					performActuatorAction(component, td, turnOffAction);
				}
			}
		}
	}

	/**
	 * Method used to actually call an action to be performed by the component handled by edge.
	 * 
	 * @param component the component that has to perform an action.
	 * @param td        the thing descriptor with all the action and properties of the component.
	 * @param action 	the name of the action to be performed. It is searched as a substring in the td,
	 * 					so it can be the full name or just part of it.
	 */
	private void performActuatorAction(final Component component, final Optional<ConsumedThing> td, final String action) {
		if (component.getActionBySubString(action).isPresent()) {
			try {
				Object responce = td.get().getAction(component.getActionBySubString(action).get())
						.invoke().get();
				System.out.println(
						component.getId() + " " + component.getCategory() + " in edge " + component.getEdgeIp()
								+ " performed " + action + " action with result " + responce);
			} catch (InterruptedException | ExecutionException e) {
				e.printStackTrace();
			}
		}
	}

}
