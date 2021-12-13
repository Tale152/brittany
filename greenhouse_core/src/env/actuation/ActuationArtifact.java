// CArtAgO artifact code for project greenhouse_core

package actuation;

import cartago.*;
import utility.Pair;

public class ActuationArtifact extends Artifact {
	void init(int initialValue) {}

	@OPERATION void actuate(Pair<String, Integer> outOfRangeSample, Pair<Integer,Integer> range) {
		Integer currentValue = outOfRangeSample.getY();
		if(currentValue < range.getX()) {
			System.out.println("Do something to increase the value. \nCurrent value: " + currentValue + " Min value: " + range.getX());
		} else if (currentValue > range.getY()) {
			System.out.println("Do something to decrease the value. \nCurrent value: " + currentValue + " Max value: " + range.getY());
		} else {
			throw new IllegalStateException("If the actuator is called, the value must be greater than the max or lower than the min value");
		}
	}
}

