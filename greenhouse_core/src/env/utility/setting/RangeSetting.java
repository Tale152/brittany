package utility.setting;

import utility.Pair;

/**
 * RangeSetting is a specific kind of Setting.
 * An RangeSetting has a category, taken from its parent class,
 * and a pair which defines the minimum and maximum value
 * accepted for a specific category of samples.
 * This can be used when the setting are based on a range of values.
 */
public class RangeSetting extends Setting {
	
	private Pair<Integer, Integer> range;
	
	/**
	 * Constructor of RangeSetting.
	 * 
	 * @param category the category that the setting is going to regulate.
	 * @param range    a pair which contains a pair of values, that are the minimum
	 * 				   and the maximum values accepted from a specific category.
	 */
	public RangeSetting(final String category, final Pair<Integer, Integer> range) {
		super(category);
		this.range = range;
	}

	/**
	 * A RangeSetting has a minimum value accepted from a specific category
	 * of sample.
	 * 
	 * @return the minimum value accepted from the category that
	 * the setting regulates.
	 */
	public int getMin() {
		return this.range.getX();
	}

	/**
	 * A RangeSetting has a maximum value accepted from a specific category
	 * of sample.
	 * 
	 * @return the maximum value accepted from the category that the
	 * setting regulates.
	 */
	public int getMax() {
		return this.range.getY();
	}

	@Override
	public String toString() {
		return "RangeSettings [range =" + this.range + " " + super.toString() + "] ";
	}

}
