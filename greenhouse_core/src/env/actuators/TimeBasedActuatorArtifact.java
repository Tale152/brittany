package actuators;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.ThingDescriptorUtility;
import utility.component.Component;
import utility.setting.HourSetting;
import utility.setting.Settings;

/**
 * TimeBasedActuatorArtifact is an Artifact that is used check periodically
 * the settings based on time in order to perform action when it is necessary.
 */
public class TimeBasedActuatorArtifact extends Artifact {
    private List<Component> components;
    private Optional<Settings> settings;
    private List<ConsumedThing> thingDescriptors;

    void init() {
        this.components = new ArrayList<>();
        this.settings = Optional.empty();
        this.thingDescriptors = new ArrayList<>();
    }

    /**
     * Operation used to set up the list of components when they are retrieved,
     * which are the components that the greenhouse can handle.
     * 
     * @param components the list of [[utility.component.Component]] found.
     */
    @OPERATION
    void setupComponents(final List<Component> components) {
        this.components = components;
    }

    /**
     * Operation used to set up the list of settings when they are retrieved,
     * which are the settings created by the user.
     * 
     * @param settings   an optional of [[utility.setting.Settings]] which contains
     *                   the settings only if they exist.
     */
    @OPERATION
    void setupSettings(final Optional<Settings> settings) {
        this.settings = settings;
    }

    /**
     * Operation used to set up the list of thing descriptors once they are
     * retrieved, which defines the action and properties of a component.
     * 
     * @param thingDescriptors list of the thing descriptors found.
     */
    @OPERATION
    void setupTds(final List<ConsumedThing> thingDescriptors) {
        this.thingDescriptors = thingDescriptors;
    }

    /**
     * Operation used to check retrieve the hour setting of a specific category of
     * components and to check if it is necessary to perform an action or not.
     * 
     * @param category the category of the hour settings that is checked.
     */
    @OPERATION
    void checkSettings(final String category) {
        if (!this.components.isEmpty() && this.settings.isPresent()
                && this.settings.get().getSetting(category).isPresent()) {
            HourSetting setting = (HourSetting) this.settings.get().getSetting(category).get();
            List<Component> actuators = ThingDescriptorUtility.getActuatorsByCategory(this.components, category);
            checkTime(setting, actuators);
        }
    }

    /**
     * Method used to check the time retrieved from the settings and the current time, 
     * in order to perform the correct action if it is necessary.
     * 
     * @param setting the HourSetting of a specific component category.
     * @param actuators the lsit of actuator that have a specific category.
     */
    private void checkTime(final HourSetting setting, final List<Component> actuators) {
        if (setting.getFromTime().compareTo(LocalTime.now()) <= 0
                && setting.getToTime().compareTo(LocalTime.now()) >= 0) {
            performActuatorAction(actuators, "On");
        } else {
            performActuatorAction(actuators, "Off");
        }
    }

    /**
     * Method used to actually call an action to be performed by the component handled by edge.
     * 
     * @param actuators the actuators that have to perform an action.
     * @param action the name of the action to be performed. It is searched as a substring in the td,
     * so it can be the full name or just part of it.
     */
    private void performActuatorAction(final List<Component> actuators, final String action) {
        for (Component c : actuators) {
            Optional<ConsumedThing> td = ThingDescriptorUtility.getThingDescriptor(this.thingDescriptors,
                    c.getEdgeIp());
            if (td.isPresent() && c.getActionBySubString(action).isPresent()) {
                try {
                    Object responce = td.get().getAction(c.getActionBySubString(action).get()).invoke().get();
                    System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp()
                            + " performed " + action + " action with result " + responce);
                } catch (InterruptedException | ExecutionException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
