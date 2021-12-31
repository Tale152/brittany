// CArtAgO artifact code for project greenhouse_core

package sampling;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import cartago.*;
import utility.Device;
import utility.Sample;
import utility.setting.RangeSetting;
import utility.setting.Setting;
import utility.setting.Settings;

/**
 * SamplingArtifact is an Artifact used to handle all the sampling operations of
 * the application.
 * Once everything is set up, every samplingAgent that is focusing on this
 * Artifact will start the sampling operation,
 * and when the samples are retrieved, the update of the information are going
 * to
 * be handled here (uploading the data
 * to the persistence service and starting an actuator if needed).
 *
 */
public class SamplingArtifact extends Artifact {

	private static final int DELTA = 1;

	private List<Device> devices;
	private Optional<Settings> settings;

	private List<Sample> lastSamples;

	void init() {
		this.lastSamples = new ArrayList<>();
	}

	/**
	 * Operation used to set up the devices and the settings, which are the basic
	 * information needed to actually start the sampling.
	 * 
	 * @param devices  a list of all the devices that are present in the
	 *                 greenhouse.
	 * @param settings the minimum and maximum values that a device of a specific
	 *                 category must observe. If it is
	 *                 not respected, an actuator is started to resolve the bad
	 *                 status.
	 */
	@OPERATION
	void setup(final List<Device> devices, final Optional<Settings> settings) {
		this.settings = settings;
		this.devices = devices;
	}

	/**
	 * Operation used to actually perform a sample. A specific samplingAgent, every
	 * delta of time, start a sample operation
	 * for a specific role of devices. This starts the communication with the
	 * devices performed by the CommunicationAgent.
	 * 
	 * @param category, every samplingAgent have a specific category, that matches
	 *                  with the
	 *                  device category. It is the type of sample that is going to
	 *                  be retrieved.
	 */
	@OPERATION
	void sampleOperation(final String category) {
		// the role can be use to filter the devices to communicate with
		defineObsProperty("communicate", getDevicesByCategory(category));
	}

	/**
	 * Operation used to update the current value of the samples, and to decide if
	 * it is necessary to send
	 * the data recorded to the persistence service and to check if an actuator had
	 * to be triggered.
	 * 
	 * @param currentSamples data retrieved from the sampling devices in the
	 *                       greenhouse.
	 */
	@OPERATION
	void updateOperation(final List<Sample> currentSamples) {
		if (!currentSamples.isEmpty()) {
			Sample avarageSample = getAvarageOfSamples(currentSamples);
			Optional<Sample> lastSample = getSampleByCategory(lastSamples, avarageSample.getCategory());
			System.out.println("Avarage current Sample: " + avarageSample + "\nLast avarage sample: " + lastSample);

			if (lastSample.isPresent()) {
				if (Math.abs(avarageSample.getValue() - lastSample.get().getValue()) > DELTA) {
					defineObsProperty("uploadPersistence", avarageSample);
					lastSamples.remove(lastSample.get());
				}
			}
			if (this.settings.isPresent()) {
				System.out.println("Settings in sampling: " +this.settings);
				if (this.settings.get().getSetting(avarageSample.getCategory()).isPresent()) {
					// TODO this has to be done only when we use a RangeSetting
					if (avarageSample.getValue() < ((RangeSetting) getSettingByCategory(avarageSample.getCategory()))
							.getMin()
							|| avarageSample
									.getValue() > ((RangeSetting) getSettingByCategory(avarageSample.getCategory()))
											.getMax()) {
						System.out.println("Create out of range behavior");
						defineObsProperty("actuate", avarageSample, getSettingByCategory(avarageSample.getCategory()));
					}
				}
			}
			this.lastSamples.add(avarageSample);
		}

	}

	private Sample getAvarageOfSamples(final List<Sample> samples) {
		Sample sample = samples.get(0);
		return new Sample(sample.getCategory(), sample.getSamplingTime(),
				(int) samples.stream().mapToInt(s -> s.getValue()).average().getAsDouble());
	}

	private Optional<Sample> getSampleByCategory(final List<Sample> samples, final String category) {
		return samples.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}

	private List<Device> getDevicesByCategory(final String category) {
		return this.devices.stream().filter(d -> d.getCategory().equals(category)).collect(Collectors.toList());
	}

	private Setting getSettingByCategory(final String category) {
		return this.settings.get().getSetting(category).get();
	}

}
