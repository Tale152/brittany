// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import cartago.*;

public class CommonArtifact extends Artifact {
	
	private List<String> devices;	
	
	void init() {
		devices = new ArrayList<>(Arrays.asList("id1", "id2", "id3"));		
		defineObsProperty("devices", devices);
	}
}
