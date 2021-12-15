// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import cartago.*;
import utility.CollectionUtility;
import utility.Pair;

public class SamplingArtifact extends Artifact {
	
	private List<String> devices;
	private Optional<Map<String, Integer>> lastSamples;
	private Map<String, Integer> deltaDevices;
	private Map<String, Pair<Integer, Integer>> thresholds;
	
	void init() {
		this.lastSamples = Optional.empty();	
		this.deltaDevices = new HashMap<>();
		this.thresholds = new HashMap<>();
	}
	
	@OPERATION void initDevices(final List<String> devices) {
		this.devices = devices;
		System.out.println("Init " + devices);
		devices.forEach(d -> this.deltaDevices.put(d, 200000));
		devices.forEach(d -> this.thresholds.put(d, new Pair<>(100000,500000)));		
	}
	
	@OPERATION void sampleOperation(final String role) {
		//the role can be use to filter the devices to communicate with
		defineObsProperty("communicate", this.devices); //you can send here the devices you want to ask data to
	}
	
	@OPERATION void updateOperation(final List<Pair<String, Integer>> data) {
		Map<String, Integer> currentSamples = CollectionUtility.toMap(data);
		System.out.println(currentSamples);
		if(!this.lastSamples.isPresent()) {
			//TODO mandare dati su db o reperire l'ultima entry su db e controllarla?
		} else {
			System.out.println("Last samples " + this.lastSamples + "\nCurrent samples " + currentSamples);
			currentSamples.forEach((k,v) -> {
				if(Math.abs(v - lastSamples.get().get(k)) > this.deltaDevices.get(k)) {
					System.out.println("Carica su db!");				
					if(v > this.thresholds.get(k).getY() || v < this.thresholds.get(k).getX()) {
						System.out.println("Create out of range behavior");
						defineObsProperty("actuate", new Pair<>(k,v), this.thresholds.get(k));
					}
				}				
			});
		}
		this.lastSamples = Optional.of(new HashMap<>(currentSamples));
	}
}
