// CArtAgO artifact code for project greenhouse_core

package communication;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import cartago.*;
import utility.Device;
import utility.Sample;

/**
 * CommunicationArtifact is the Artifact that is going to communicate with sampling devices 
 * in order to retrieve the samples needed.
 * 
 */
public class CommunicationArtifact extends Artifact {

	private List<Sample> samples;
	
	void init() {}

	/**
	 * Operation used to retrieve samples from a certain list of sampling devices.
	 * @param devices a list of devices that the agent is going to communicate with to retrieve samples.
	 * @param retrievedSamples the samples retrieved that are going to be returned to the agent that called this operation.
	 */
	@OPERATION void getSamplesOperation(List<Device> devices, OpFeedbackParam<List<Sample>> retrievedSamples) {
		this.samples = new ArrayList<>();
		System.out.println("Communicating with " + devices);
		devices.forEach(d -> this.samples.add(new Sample(d.getRole(), Instant.now().toString(), new Random().nextInt(20))));
		retrievedSamples.set(this.samples);
	}
	
}
