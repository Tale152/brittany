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
	 * Given a list of Samples, this methods calculates the average of them,
	 * return a Sample that is the average.
	 * 
	 * @param samples the list of samples that are going to be used to calculate
	 * 				  the average.
	 * @return a sample that is the average of all the samples given as argument.
	 */
    public static Sample getAverageOfSamples(final List<Sample> samples) {
		Sample sample = samples.get(0);
		return new Sample(sample.getCategory(), sample.getSamplingTime(),
				(int) samples.stream().mapToInt(s -> s.getValue()).average().getAsDouble());
	}

	/**
	 * Given a list of samples and a category, this method is used to find
	 * the first sample in the list of the specified category.
	 * 
	 * @param samples  the list of sample to examin.
	 * @param category the category of the sample wanted.
	 * @return return an optional of the sample of the category specified 
	 * if found, optional of empty otherwise.
	 */
	public static Optional<Sample> getSampleByCategory(final List<Sample> samples, final String category) {
		return samples.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}
	
}
