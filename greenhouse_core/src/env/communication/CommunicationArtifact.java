// CArtAgO artifact code for project greenhouse_core

package communication;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
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
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.thingDescriptors = new ArrayList<>();
	}

	@OPERATION
	void setupTds(final List<ConsumedThing> thingDescriptors) {
		this.thingDescriptors = thingDescriptors;
	}

	/**
	 * Operation used to retrieve samples from a certain list of sampling components.
	 * 
	 * @param components       a list of components that the agent is going to
	 *                         communicate with to retrieve samples.
	 * @param retrievedSamples the samples retrieved that are going to be returned
	 *                         to the agent that called this operation.
	 */
	@OPERATION
	void getSamplesOperation(final List<Component> components, OpFeedbackParam<List<Sample>> retrievedSamples) {
		this.samples = new ArrayList<>();
		System.out.println("Communicating with " + components);

		for (Component component : components) {
			Optional<ConsumedThing> td = getThingDescriptor(component.getEdgeIp());
			if (td.isPresent() && component.getPropertyBySubString(component.getCategory()).isPresent()) {
				try {
					double value = (Double) td.get().getProperty(component.getPropertyBySubString(component.getCategory()).get()).read().get();
					samples.add(new Sample(component.getCategory(), Instant.now().toString(), (int) Math.round(value)));
				} catch (InterruptedException | ExecutionException e) {
					e.printStackTrace();
				}
			}
		}
		retrievedSamples.set(this.samples);
	}

	private Optional<ConsumedThing> getThingDescriptor(final String id) {
		return this.thingDescriptors.stream().filter(t -> t.getId().equals(id)).findFirst();
	}

}
