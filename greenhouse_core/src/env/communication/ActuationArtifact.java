// CArtAgO artifact code for project greenhouse_core

package communication;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;
import java.util.stream.Collectors;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.Sample;
import utility.component.Component;
import utility.setting.HourSetting;
import utility.setting.RangeSetting;
import utility.setting.Settings;

/**
 * ActautionArtifact is an Artifact that is used to send a message to an actuator to 
 * handle when the current sample registered is bigger or lower than the setting of
 * a specific device category.
 *
 */
public class ActuationArtifact extends Artifact {
	
	private List<Component> components;
	private Optional<Settings> settings;
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.components = new ArrayList<>();
		this.settings = Optional.empty();
		this.thingDescriptors = new ArrayList<>();
	}

	@OPERATION
	void setupComponents(final List<Component> components, final Optional<Settings> settings) {
		this.settings = settings;
		this.components = components;
	}

	@OPERATION
	void setupTd(final List<ConsumedThing> thingDescriptors) {
		this.thingDescriptors = thingDescriptors;
	}

	@OPERATION
	void checkSettings(final String category) {
		if (!this.components.isEmpty() && this.settings.isPresent() && this.settings.get().getSetting(category).isPresent()){
			HourSetting setting = (HourSetting) this.settings.get().getSetting(category).get();
			List<Component> actuators = getActuatorsByCategory(category);

			if (setting.getFromTime().compareTo(LocalTime.now()) <= 0 && setting.getToTime().compareTo(LocalTime.now()) >= 0) {
				for (Component c : actuators){
					Optional<ConsumedThing> td = getThingDescriptor(c.getEdgeIp());
					System.out.println(c.getActionBySubString("On"));
					if (td.isPresent() && c.getActionBySubString("On").isPresent()) {
						try {
							Object responce = td.get().getAction(c.getActionBySubString("On").get()).invoke().get();
							System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp() + " performed On action with result " + responce);
						} catch (InterruptedException | ExecutionException e) {
							e.printStackTrace();
						}
					}
				}
			} else {
				for (Component c : actuators){
					Optional<ConsumedThing> td = getThingDescriptor(c.getEdgeIp());
					System.out.println(c.getActionBySubString("Off"));
					if (td.isPresent() && c.getActionBySubString("Off").isPresent()) {
						try {
							Object responce = td.get().getAction(c.getActionBySubString("Off").get()).invoke().get();
							System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp() + " performed Off action with result " + responce);
						} catch (InterruptedException | ExecutionException e) {
							e.printStackTrace();
						}
					}
				}
			}
		}
	}
	
	private List<Component> getActuatorsByCategory(final String category) {
		return this.components.stream().filter(c -> c.getCategory().equals(category)).filter(c -> !c.getActions().isEmpty()).collect(Collectors.toList());
	}

	private Optional<ConsumedThing> getThingDescriptor(final String id) {
		return this.thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
	}

	/**
	 * Used to check the current sample and to notify if it is bigger or lower that the settings.
	 * @param outOfRangeSample the sample is out of range base on the settings.
	 * @param setting the setting of the specific category of the sample.
	 */
	@OPERATION void actuate(final Sample outOfRangeSample, final RangeSetting setting) {
		int currentValue = outOfRangeSample.getValue();
		
		if(currentValue < setting.getMin()) {
			System.out.println("Do something to increase the value. \nCurrent value: " + currentValue + " Min value: " + setting.getMin());
		} else if (currentValue > setting.getMax()) {
			System.out.println("Do something to decrease the value. \nCurrent value: " + currentValue + " Max value: " + setting.getMax());
		} else {
			throw new IllegalStateException("If the actuator is called, the value must be greater than the max or lower than the min value");
		}
	}
}
