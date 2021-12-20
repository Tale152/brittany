// CArtAgO artifact code for project greenhouse_core

package common;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import cartago.*;
import utility.Device;
import utility.Pair;
import utility.Thresholds;

/**
 * CommonArtifact is the core Artifact of this JaCaMo application.
 * Its main role is to wait for the retrieval of the authentication token, and then it starts the
 * sampling activity, initializing all the data that the other agents will need.
 *
 */
public class CommonArtifact extends Artifact {
	
	private String authenticationToken;

	private List<Device> devices;
	private Thresholds thresholds;

	void init() {}

	/**
	 * Operation used when the token for the authentication has been retrieved, to actually create the instances of all 
	 * data used from the other agents.
	 * @param token the authentication token retrieved from the server, used for authentication purposes during the
	 * communication with other servers.
	 */
	@OPERATION void initAfterAuthentication(final String token) {
		this.authenticationToken = token;
		
		//for test purpose right now devices and thresholds are hard-coded
		devices = new ArrayList<>(Arrays.asList(new Device("id1", "temperature"), new Device("id2", "light"),
				new Device("id3", "temperature")));

		thresholds = new Thresholds();
		thresholds.addThreshold("temperature", new Pair<>(1000, 3000));
		thresholds.addThreshold("light", new Pair<>(1000, 3000));

		defineObsProperty("setup", devices, thresholds);
	}
}
