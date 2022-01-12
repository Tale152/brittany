// CArtAgO artifact code for project greenhouse_core

package communication;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import cartago.*;
import utility.Sample;
import utility.component.Component;

/**
 * CommunicationArtifact is the Artifact that is going to communicate with
 * sampling devices
 * in order to retrieve the samples needed.
 * 
 */
public class CommunicationArtifact extends Artifact {

	private List<Sample> samples;

	void init() {}

	/**
	 * Operation used to retrieve samples from a certain list of sampling components.
	 * 
	 * @param components       a list of components that the agent is going to
	 *                         communicate with to retrieve samples.
	 * @param retrievedSamples the samples retrieved that are going to be returned
	 *                         to the agent that called this operation.
	 */
	@OPERATION
	void getSamplesOperation(List<Component> components, OpFeedbackParam<List<Sample>> retrievedSamples) {
		this.samples = new ArrayList<>();
		//System.out.println("Communicating with " + components);
		components.forEach(d -> this.samples.add(new Sample(d.getCategory(),
				Instant.now().toString(), new Random().nextInt(20))));
		retrievedSamples.set(this.samples);
	}

}
