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

public class TimeBasedActuatorArtifact extends Artifact {
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
            List<Component> actuators = ThingDescriptorUtility.getActuatorsByCategory(this.components, category);
            if (setting.getFromTime().compareTo(LocalTime.now()) <= 0
                    && setting.getToTime().compareTo(LocalTime.now()) >= 0) {
                performActuatorAction(actuators, "On");
            } else {
                performActuatorAction(actuators, "Off");
            }
        }
    }

    private void performActuatorAction(final List<Component> actuators, final String actionToPerform) {
        for (Component c : actuators) {
            Optional<ConsumedThing> td = ThingDescriptorUtility.getThingDescriptor(this.thingDescriptors, c.getEdgeIp());
            if (td.isPresent() && c.getActionBySubString(actionToPerform).isPresent()) {
                try {
                    Object responce = td.get().getAction(c.getActionBySubString(actionToPerform).get()).invoke().get();
                    System.out.println(c.getId() + " " + c.getCategory() + " in edge " + c.getEdgeIp()
                            + " performed " + actionToPerform + " action with result " + responce);
                } catch (InterruptedException | ExecutionException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
