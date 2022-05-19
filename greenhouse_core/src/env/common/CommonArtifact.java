/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// CArtAgO artifact code for project greenhouse_core

package common;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import cartago.*;
import city.sane.wot.thing.ConsumedThing;
import utility.component.Component;
import utility.setting.Settings;

/**
 * CommonArtifact is the core Artifact of this JaCaMo application.
 * It is used as a common container of the information that mostly all the 
 * agents need.
 * In order to avoid an high dependency between agents, to retrieve the basic
 * information it is used this Artifact.
 * It shares the settings, the tds and the componets using observable properties,
 * and the agents that need those information have plans to store them in their BB.
 *
 */
public class CommonArtifact extends Artifact {

	private List<Component> components;
	private Optional<Settings> settings;
	private List<ConsumedThing> thingDescriptors;

	void init() {
		this.components = new ArrayList<>();
		this.settings = Optional.empty();
		this.thingDescriptors = new ArrayList<>();

		//defines the observable property during the initialization
		defineObsProperty("setupSettings", this.settings);
		defineObsProperty("setupComponents", this.components);
		defineObsProperty("setupTds", this.thingDescriptors);
	}

	/**
	 * Operation used to share a list of all the Components that are found in the greenhouse
	 * to all the agents that observe this Artifact and have "setupComponents" in their plans.
	 * 
	 * @param components the list of Components found.
	 */
	@OPERATION
	void shareComponents(final List<Component> components) {
		if (!this.components.equals(components)) {
			this.components = components;
		}
		updateObsProperty("setupComponents", this.components);
	}

	/**
	 * Operation used to share the Settings that are found in the greenhouse
	 * to all the agents that observe this Artifact and have "setupSettings" in their plans.
	 * The settings are Optional, because their might be not set by the user.
	 * 
	 * @param settings an optional of the Settings found.
	 */
	@OPERATION
	void shareSettings(final Optional<Settings> settings) {
		if (!this.settings.equals(settings)) {
			this.settings = settings;
		}
		updateObsProperty("setupSettings", this.settings);
	}

	/**
	 * Operation used to share a list of all the Thing Descriptors that are found
	 * to all the agents that observe this Artifact and have "setupTds" in their plans.
	 * 
	 * @param thingDescriptors the list of Thing Descriptors found.
	 */
	@OPERATION
	void shareThingDescriptors(final List<ConsumedThing> thingDescriptors) {
		if (!this.thingDescriptors.equals(thingDescriptors)) {
			this.thingDescriptors = thingDescriptors;
		}
		updateObsProperty("setupTds", this.thingDescriptors);
	}
}
