// CArtAgO artifact code for project greenhouse_core

package communication;

import java.util.List;
import java.util.Random;

import cartago.*;
import utility.Device;

public class CommunicationArtifact extends Artifact {
	
	void init() {}

	@OPERATION void communicate(List<Device> devices, OpFeedbackParam<List<Device>> data) {
		System.out.println("Communicating with " + devices);
		devices.forEach(d -> d.setCurrentValue(new Random().nextInt()));
		data.set(devices);
	}
}
