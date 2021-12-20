// CArtAgO artifact code for project greenhouse_core

package actuation;

import cartago.*;
import utility.Device;
import utility.Pair;

/**
 * ActautionArtifact is an Artifact that is used to send a message to an actuator to 
 * handle when the current sample registered is bigger or lower than the threshold set for
 * a specific device role.
 *
 */
public class ActuationArtifact extends Artifact {
	void init(int initialValue) {}

	/**
	 * Used to check the current sample and to notify if it is bigger or lower that the threshold.
	 * @param outOfRangeDevice, the device that registered the out of range sample.
	 * @param threshold, the threshold of the specific role of the device.
	 */
	@OPERATION void actuate(Device outOfRangeDevice, Pair<Integer,Integer> threshold) {
		Integer currentValue = outOfRangeDevice.getCurrentValue();
		if(currentValue < threshold.getX()) {
			System.out.println("Do something to increase the value. \nCurrent value: " + currentValue + " Min value: " + threshold.getX());
		} else if (currentValue > threshold.getY()) {
			System.out.println("Do something to decrease the value. \nCurrent value: " + currentValue + " Max value: " + threshold.getY());
		} else {
			throw new IllegalStateException("If the actuator is called, the value must be greater than the max or lower than the min value");
		}
	}
}
