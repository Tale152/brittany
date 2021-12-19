// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import cartago.*;
import utility.Device;
import utility.Thresholds;

public class SamplingArtifact extends Artifact {
	
	private static final int DELTA = 1;
	
	private List<Device> devices;
	private Thresholds thresholds;
	
	private Optional<Map<String, Integer>> lastSamples;
	
	void init() {
		this.lastSamples = Optional.empty();
	}
	
	@OPERATION void setup(final List<Device> devices, final Thresholds thresholds) {
		this.thresholds = thresholds;
		this.devices = devices;
		System.out.println("Init " + this.devices + " " + this.thresholds);
	}
	
	@OPERATION void sampleOperation(final String role) {
		//the role can be use to filter the devices to communicate with
		defineObsProperty("communicate", this.devices); //you can send here the devices you want to ask data to
	}
	
	@OPERATION void updateOperation(final List<Device> currentSamples) {
		if(!this.lastSamples.isPresent()) {
			//TODO mandare dati su db o reperire l'ultima entry su db e controllarla?
		} else {
			System.out.println("Last samples " + this.lastSamples + "\nCurrent samples " + currentSamples);
			currentSamples.forEach(d -> {
				if(Math.abs(d.getCurrentValue() - lastSamples.get().get(d.getId())) > DELTA) {
					System.out.println("Carica su db!");
					if(this.thresholds.getThreshold(d.getRole()).isPresent()) {
						if(d.getCurrentValue() > this.thresholds.getThreshold(d.getRole()).get().getY() || d.getCurrentValue() < this.thresholds.getThreshold(d.getRole()).get().getX()) {
							System.out.println("Create out of range behavior");
							defineObsProperty("actuate", d, this.thresholds.getThreshold(d.getRole()).get());
						}
					}
				}
			});
		}
		
		this.lastSamples = Optional.of(new HashMap<>());
		currentSamples.forEach((d) -> this.lastSamples.get().put(d.getId(), d.getCurrentValue()));		
	}
}
