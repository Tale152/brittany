// CArtAgO artifact code for project greenhouse_core

package actuation;

import cartago.*;
import utility.Device;
import utility.Pair;
import utility.settings.RangeSetting;

/**
 * ActautionArtifact is an Artifact that is used to send a message to an actuator to 
 * handle when the current sample registered is bigger or lower than the setting of
 * a specific device category.
 *
 */
public class ActuationArtifact extends Artifact {
	
	void init(int initialValue) {}

	/**
	 * Used to check the current sample and to notify if it is bigger or lower that the threshold.
	 * @param outOfRangeDevice the device that registered the out of range sample.
	 * @param setting the setting of the specific category of the device.
	 */
	@OPERATION void actuate(Device outOfRangeDevice, RangeSetting setting) {
		int currentValue = outOfRangeDevice.getCurrentValue();
		Pair<Integer, Integer> range = setting.getRange();
		
		if(currentValue < range.getX()) {
			System.out.println("Do something to increase the value. \nCurrent value: " + currentValue + " Min value: " + range.getX());
		} else if (currentValue > range.getY()) {
			System.out.println("Do something to decrease the value. \nCurrent value: " + currentValue + " Max value: " + range.getY());
		} else {
			throw new IllegalStateException("If the actuator is called, the value must be greater than the max or lower than the min value");
		}
	}
}
