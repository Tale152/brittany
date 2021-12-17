// CArtAgO artifact code for project greenhouse_core

package actuation;

import cartago.*;
import utility.Device;
import utility.Pair;

public class ActuationArtifact extends Artifact {
	void init(int initialValue) {}

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
