// CArtAgO artifact code for project greenhouse_core

package common;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import cartago.*;
import utility.Device;
import utility.Pair;
import utility.Thresholds;

public class CommonArtifact extends Artifact {

	private List<Device> devices;
	private Thresholds thresholds;

	void init() {}

	@OPERATION
	void initAfterAuthentication() {
		devices = new ArrayList<>(Arrays.asList(new Device("id1", "temperature"), new Device("id2", "light"),
				new Device("id3", "temperature")));

		thresholds = new Thresholds();
		thresholds.addThreshold("temperature", new Pair<>(1000, 3000));
		thresholds.addThreshold("light", new Pair<>(1000, 3000));

		//defineObsProperty("setup", devices, thresholds);
	}
}
