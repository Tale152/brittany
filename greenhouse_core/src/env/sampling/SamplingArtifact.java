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
 * SamplingArtifact is the Artifact that is going to communicate with
 * sampling components in order to retrieve the samples needed.
 */
public class SamplingArtifact extends Artifact {

	private List<Sample> samples;
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.thingDescriptors = new ArrayList<>();
		this.samples = new ArrayList<>();
		defineObsProperty("checkSamples", this.samples);
	}

	/**
	 * Operation used to set up the list of thing descriptors once they are
	 * retrieved, which defines the action and properties of a component.
	 * 
	 * @param thingDescriptors list of the thing descriptors found.
	 */
	@OPERATION
	void setupTds(final List<ConsumedThing> thingDescriptors) {
		this.thingDescriptors = thingDescriptors;
	}

	/**
	 * Operation used to retrieve samples from a certain list of sampling
	 * components.
	 * 
	 * @param components a list of components that the agent is going to
	 *                   communicate with to retrieve samples.
	 */
	@OPERATION
	void getSamples(final List<Component> components) {
		this.samples = new ArrayList<>();
		System.out.println("Communicating with " + components);
		for (Component component : components) {
			handleComponentSample(component);
		}
		// the samples retrieved are going to trigger the sampling coordinator agent plan
		updateObsProperty("checkSamples", this.samples);
	}

	/**
	 * Utility method that is used to actually communicate with the components.
	 * Using the thing descriptor of a component, this method retieve the property
	 * of the category of the component and add it to the list of samples retreived.
	 * 
	 * @param component the component where the sample is currently being retrieved.
	 */
	private void handleComponentSample(final Component component) {
		Optional<ConsumedThing> td = ThingDescriptorUtility.getThingDescriptor(this.thingDescriptors, component.getEdgeIp());
		if (td.isPresent() && component.getPropertyBySubString(component.getCategory()).isPresent()) {
			try {
				double value = (Double) td.get().getProperty(component.getPropertyBySubString(component.getCategory()).get()).read().get();
				this.samples.add(new Sample(component.getCategory(), Instant.now().toString(), (int) Math.round(value)));
			} catch (InterruptedException | ExecutionException e) {
				e.printStackTrace();
			}
		}
	}

}
