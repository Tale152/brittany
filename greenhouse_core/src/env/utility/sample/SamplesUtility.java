package utility.sample;

import java.util.List;
import java.util.Optional;

public class SamplesUtility {

    public static Sample getAvarageOfSamples(final List<Sample> samples) {
		Sample sample = samples.get(0);
		return new Sample(sample.getCategory(), sample.getSamplingTime(),
				(int) samples.stream().mapToInt(s -> s.getValue()).average().getAsDouble());
	}

	public static Optional<Sample> getSampleByCategory(final List<Sample> samples, final String category) {
		return samples.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}
}
