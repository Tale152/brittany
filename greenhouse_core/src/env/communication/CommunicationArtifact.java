// CArtAgO artifact code for project greenhouse_core

package communication;

import java.util.List;
import java.util.Random;

import cartago.*;
import utility.Device;

/**
 * CommunicationArtifact is the Artifact that is going to communicate with sampling devices 
 * in order to retrieve the samples needed.
 * 
 */
public class CommunicationArtifact extends Artifact {
	
	void init() {}

	/**
	 * Operation used to retrieve samples from a certain list of sampling devices.
	 * @param devices a list of devices that the agent is going to communicate with to retrieve samples.
	 * @param data the samples retrieved that are going to be returned to the agent that called this operation.
	 */
	@OPERATION void getSamplesOperation(List<Device> devices, OpFeedbackParam<List<Device>> data) {
		System.out.println("Communicating with " + devices);
		devices.forEach(d -> d.setCurrentValue(new Random().nextInt(3000)));
		data.set(devices);
	}
}
