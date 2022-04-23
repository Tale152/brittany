// CArtAgO artifact code for project greenhouse_core

package actuators;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.Sample;
import utility.ThingDescriptorUtility;
import utility.component.Component;
import utility.setting.RangeSetting;

/**
 * ActautionArtifact is an Artifact that is used to send a message to an
 * actuator to handle when the current sample registered is bigger or lower 
 * than the setting of a specific device category.
 * Its aim is also to keep checking the HourSettings, in order
 * to actuate when a certain time in the settings is reached.
 */
public class SampleBasedActuatorArtifact extends Artifact {

	private List<Component> components;
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.components = new ArrayList<>();
		this.thingDescriptors = new ArrayList<>();
	}

	@OPERATION
	void setupComponents(final List<Component> components) {
		this.components = components;
	}

	@OPERATION
	void setupTd(final List<ConsumedThing> thingDescriptors) {
		this.thingDescriptors = thingDescriptors;
	}

	/**
	 * Used to check the current sample and to notify if it is bigger or lower that
	 * the settings.
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

	private void switchActuatorAction(final String category, final String turnOnAction, final String turnOffAction) {
		List<Component> components = ThingDescriptorUtility.getActuatorsByCategory(this.components, category);
		for (Component component : components) {
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
