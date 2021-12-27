// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

import cartago.*;
import utility.Device;
import utility.settings.RangeSetting;
import utility.settings.Settings;

/**
 * SamplingArtifact is an Artifact used to handle all the sampling operations of the application.
 * Once everything is set up, every samplingAgent that is focusing on this Artifact will start the sampling operation,
 * and when the samples are retried, the update of the information are going to be handled here (uploading the data
 * to the persistence service and starting an actuator if needed).
 *
 */
public class SamplingArtifact extends Artifact {
	
	private static final int DELTA = 1;
	
	private List<Device> devices;
	private Optional<Settings> settings;
	
	private Optional<Map<String, Integer>> lastSamples;
	
	void init() {
		this.lastSamples = Optional.empty();
	}
	
	/**
	 * Operation used to set up the devices and the thresholds, which are the basic information
	 * needed to actually start the sampling.
	 * @param devices a list of all the devices that are present in the greenhouse.
	 * @param thresholds the minimum and maximum values that a device of a specific role must observe. If it is 
	 * not respected, an actuator is started to resolve the bad status.
	 */
	@OPERATION void setup(final List<Device> devices, final Optional<Settings> settings) {
		this.settings = settings;
		this.devices = devices;
		System.out.println("Init " + this.devices + " " + this.settings);
	}
	
	/**
	 * Operation used to actually perform a sample. A specific samplingAgent, every delta of time, start a sample operation
	 * for a specific role of devices. This starts the communication with the devices performed by the CommunicationAgent.
	 * @param role, every SamplingAgent have a specific role, that matches with the device role. It is the type of 
	 * sample that is going to be retrieved.
	 */
	@OPERATION void sampleOperation(final String role) {
		//the role can be use to filter the devices to communicate with
		defineObsProperty("communicate",
				this.devices.stream().filter(d -> d.getRole().equals(role)).collect(Collectors.toList())); 
	}
	
	/**
	 * Operation used to update the current value of the samples, and to decide if it is necessary to send
	 * the data recorded to the persistence service and to check if an actuator had to be triggered.
	 * @param currentSamples data retrieved from the sampling devices in the greenhouse.
	 */
	@OPERATION void updateOperation(final List<Device> currentSamples) {
		if(!this.lastSamples.isPresent()) {
			//TODO mandare dati su db o reperire l'ultima entry su db e controllarla?
		} else {
			System.out.println("Last samples " + this.lastSamples + "\nCurrent samples " + currentSamples);
			currentSamples.forEach(d -> {
				if(Math.abs(d.getCurrentValue() - lastSamples.get().get(d.getId())) > DELTA) {
					System.out.println("Carica su db!");
					if(this.settings.isPresent()) {
						if(this.settings.get().getSetting(d.getRole()).isPresent()) {
							//TODO this has to be done only when we use a RangeSetting
							if(d.getCurrentValue() > ((RangeSetting) this.settings.get().getSetting(d.getRole()).get()).getRange().getX() || d.getCurrentValue() < ((RangeSetting) this.settings.get().getSetting(d.getRole()).get()).getRange().getY()) {
								System.out.println("Create out of range behavior");
								defineObsProperty("actuate", d, this.settings.get().getSetting(d.getRole()).get());
							}
						}
					}					
				}
			});
		}
		
		this.lastSamples = Optional.of(new HashMap<>());
		currentSamples.forEach((d) -> this.lastSamples.get().put(d.getId(), d.getCurrentValue()));		
	}
}
