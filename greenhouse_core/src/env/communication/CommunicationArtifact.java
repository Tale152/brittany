// CArtAgO artifact code for project greenhouse_core

package communication;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import cartago.*;
import utility.Pair;

public class CommunicationArtifact extends Artifact {
	private List<Pair<String, Integer>> currentSamples;
	
	void init() {}

	@OPERATION void communicate(List<String> devices, OpFeedbackParam<List<Pair<String, Integer>>> data) {
		this.currentSamples = new ArrayList<>();
		System.out.println("Communicating with " + devices);
		devices.forEach(d -> this.currentSamples.add(new Pair<>(d, new Random().nextInt())));
		data.set(this.currentSamples);
	}
}
