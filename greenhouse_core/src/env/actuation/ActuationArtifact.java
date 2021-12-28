// CArtAgO artifact code for project greenhouse_core

package actuation;

import cartago.*;
import utility.Pair;
import utility.Sample;
import utility.setting.RangeSetting;

/**
 * ActautionArtifact is an Artifact that is used to send a message to an actuator to 
 * handle when the current sample registered is bigger or lower than the setting of
 * a specific device category.
 *
 */
public class ActuationArtifact extends Artifact {
	
	void init() {}

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
