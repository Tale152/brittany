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
 * ActautionArtifact is an Artifact that is used to send a message to an
 * actuator to handle when the current sample registered is bigger or lower 
 * than the setting of a specific device category.
 * Its aim is also to keep checking the HourSettings, in order
 * to actuate when a certain time in the settings is reached.
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
		if (!this.components.isEmpty() && this.settings.isPresent()
				&& this.settings.get().getSetting(category).isPresent()) {
			HourSetting setting = (HourSetting) this.settings.get().getSetting(category).get();
			List<Component> actuators = getActuatorsByCategory(category);

			if (setting.getFromTime().compareTo(LocalTime.now()) <= 0
					&& setting.getToTime().compareTo(LocalTime.now()) >= 0) {
				for (Component c : actuators) {
					Optional<ConsumedThing> td = getThingDescriptor(c.getEdgeIp());
					if (td.isPresent() && c.getActionBySubString("On").isPresent()) {
						try {
							Object responce = td.get().getAction(c.getActionBySubString("On").get()).invoke().get();
							System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp()
									+ " performed On action with result " + responce);
						} catch (InterruptedException | ExecutionException e) {
							e.printStackTrace();
						}
					}
				}
			} else {
				for (Component c : actuators) {
					Optional<ConsumedThing> td = getThingDescriptor(c.getEdgeIp());
					if (td.isPresent() && c.getActionBySubString("Off").isPresent()) {
						try {
							Object responce = td.get().getAction(c.getActionBySubString("Off").get()).invoke().get();
							System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp()
									+ " performed Off action with result " + responce);
						} catch (InterruptedException | ExecutionException e) {
							e.printStackTrace();
						}
					}
				}
			}
		}
	}

	private List<Component> getActuatorsByCategory(final String category) {
		return this.components.stream().filter(c -> c.getCategory().equals(category))
				.filter(c -> !c.getActions().isEmpty()).collect(Collectors.toList());
	}

	private Optional<ConsumedThing> getThingDescriptor(final String id) {
		return this.thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
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
				if (isLowerThanMin(currentValue, setting)) {
					System.out.println("Current temperature " + currentValue + " Min value " + setting.getMin());
					increaseActuator("temperature", "heatOn", "coolOff");
				} else if (isHigherThanMax(currentValue, setting)) {
					System.out.println("Current temperature " + currentValue + " Max value " + setting.getMax());
					decreaseActuator("temperature", "heatOff", "coolOn");
				} else {
					throw new IllegalStateException("The value must be lower than min or higher than max");
				};
				break;
			case "airHumidity":
				if (isLowerThanMin(currentValue, setting)) {
					System.out.println("Current humidity " + currentValue + " Min value " + setting.getMin());
					increaseActuator("humidity", "humidifyOn", "dehumidifyOff");
				} else if (isHigherThanMax(currentValue, setting)) {
					System.out.println("Current humididty " + currentValue + " Max value " + setting.getMax());
					decreaseActuator("temperature", "humidifyOff", "dehumidifyOn");
				} else {
					throw new IllegalStateException("The value must be lower than min or higher than max");
				};
				break;
		}

	}

	private boolean isLowerThanMin(final int currentValue, final RangeSetting setting) {
		return currentValue < setting.getMin();
	}

	private boolean isHigherThanMax(final int currentValue, final RangeSetting setting) {
		return currentValue > setting.getMax();
	}

	private void increaseActuator(final String category, final String increseActionName,
			final String decreaseActionName) {
		List<Component> components = getActuatorsByCategory(category);
		for (Component component : components) {
			Optional<ConsumedThing> td = getThingDescriptor(component.getEdgeIp());
			if (td.isPresent()) {
				if (component.getActionBySubString(increseActionName).isPresent()) {
					try {
						Object responce = td.get().getAction(component.getActionBySubString(increseActionName).get())
								.invoke().get();
						System.out.println(
								component.getId() + " " + component.getCategory() + " in edge " + component.getEdgeIp()
										+ " performed " + increseActionName + " action with result " + responce);
					} catch (InterruptedException | ExecutionException e) {
						e.printStackTrace();
					}
				}
				if (component.getActionBySubString(decreaseActionName).isPresent()) {
					try {
						Object responce = td.get().getAction(component.getActionBySubString(decreaseActionName).get())
								.invoke().get();
						System.out.println(
								component.getId() + " " + component.getCategory() + " in edge " + component.getEdgeIp()
										+ " performed " + decreaseActionName + " action with result " + responce);
					} catch (InterruptedException | ExecutionException e) {
						e.printStackTrace();
					}
				}
			}
		}
	}

	private void decreaseActuator(final String category, final String increseActionName,
			final String decreaseActionName) {
		List<Component> components = getActuatorsByCategory(category);
		for (Component component : components) {
			Optional<ConsumedThing> td = getThingDescriptor(component.getEdgeIp());
			if (td.isPresent()) {
				if (component.getActionBySubString(decreaseActionName).isPresent()) {
					try {
						Object responce = td.get().getAction(component.getActionBySubString(decreaseActionName).get())
								.invoke().get();
						System.out.println(
								component.getId() + " " + component.getCategory() + " in edge " + component.getEdgeIp()
										+ " performed " + decreaseActionName + " action with result " + responce);
					} catch (InterruptedException | ExecutionException e) {
						e.printStackTrace();
					}
				}
				if (component.getActionBySubString(increseActionName).isPresent()) {
					try {
						Object responce = td.get().getAction(component.getActionBySubString(increseActionName).get())
								.invoke().get();
						System.out.println(
								component.getId() + " " + component.getCategory() + " in edge " + component.getEdgeIp()
										+ " performed " + increseActionName + " action with result " + responce);
					} catch (InterruptedException | ExecutionException e) {
						e.printStackTrace();
					}
				}
			}
		}
	}
}
