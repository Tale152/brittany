// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.Sample;
import utility.ThingDescriptorUtility;
import utility.component.Component;

/**
 * CommunicationArtifact is the Artifact that is going to communicate with
 * sampling devices
 * in order to retrieve the samples needed.
 * 
 */
public class SamplingArtifact extends Artifact {

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
	void getSamples(final List<Component> components) {
		this.samples = new ArrayList<>();
		System.out.println("Communicating with " + components);
		for (Component component : components) {
			Optional<ConsumedThing> td = ThingDescriptorUtility.getThingDescriptor(this.thingDescriptors, component.getEdgeIp());
			if (td.isPresent() && component.getPropertyBySubString(component.getCategory()).isPresent()) {
				try {
					double value = (Double) td.get().getProperty(component.getPropertyBySubString(component.getCategory()).get()).read().get();
					samples.add(new Sample(component.getCategory(), Instant.now().toString(), (int) Math.round(value)));
				} catch (InterruptedException | ExecutionException e) {
					e.printStackTrace();
				}
			}
		}
		defineObsProperty("checkSamples", this.samples);
	}

}
