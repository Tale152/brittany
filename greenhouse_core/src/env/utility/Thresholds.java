package utility;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

/**
 * Thresholds are the minimum and the maximum value that a certain type of sample can have inside the greenhouse.
 * 
 */
public class Thresholds {
	private Map<String, Pair<Integer, Integer>> thresholds;
	
	public Thresholds() {
		this.thresholds = new HashMap<>();
	}

	public void addThreshold(final String role, final Pair<Integer, Integer> threshold) {
		this.thresholds.put(role, threshold);
	}
	
	public Optional<Pair<Integer,Integer>> getThreshold(final String role){
		if (this.thresholds.containsKey(role)) {
			return Optional.of(this.thresholds.get(role));
		}
		return Optional.empty();
	}
	
	@Override
	public String toString() {
		return "Thresholds [thresholds=" + thresholds + "]";
	}

}
