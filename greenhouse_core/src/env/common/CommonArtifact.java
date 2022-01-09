// CArtAgO artifact code for project greenhouse_core

package common;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import cartago.*;
import utility.component.Component;
import utility.setting.Settings;

/**
 * CommonArtifact is the core Artifact of this JaCaMo application.
 * Its main role is to wait for the retrieval of the authentication token, and
 * then it starts the
 * sampling activity, initializing all the data that the other agents will need.
 *
 */
public class CommonArtifact extends Artifact {

	private List<Component> components;
	private Optional<Settings> settings;

	void init() {
		// for test purpose right now devices are hard-coded
		this.components = new ArrayList<>();
		this.settings = Optional.empty();

		defineObsProperty("setup", components, this.settings);
	}

	@OPERATION
	void shareDevices(final List<Component> components) {
		if (!this.components.equals(components)) {
			this.components = components;
		}
		updateObsProperty("setup", this.components, this.settings);
	}

	@OPERATION
	void shareSettings(final Optional<Settings> settings) {
		if (!this.settings.equals(settings)) {
			this.settings = settings;
			updateObsProperty("setup", this.components, this.settings);
		}
	}
}
