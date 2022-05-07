package utility.sample;

import java.util.List;
import java.util.Optional;

/**
 * Utility class for list of [[utility.sample.Sample]], in order to retrieve
 * specific samples without having to implement the same methods in more
 * classes.
 */
public class SamplesUtility {

	/**
	 * Given a list of Samples, this methods calculates the av
	 * 
	 * @param samples
	 * @return
	 */
    public static Sample getAverageOfSamples(final List<Sample> samples) {
		Sample sample = samples.get(0);
		return new Sample(sample.getCategory(), sample.getSamplingTime(),
				(int) samples.stream().mapToInt(s -> s.getValue()).average().getAsDouble());
	}

	public static Optional<Sample> getSampleByCategory(final List<Sample> samples, final String category) {
		return samples.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}
}
