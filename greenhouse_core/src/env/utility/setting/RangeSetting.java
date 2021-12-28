package utility.setting;

import utility.Pair;

public class RangeSetting extends Setting {
	
	private Pair<Integer, Integer> range;
	
	public RangeSetting(final String category, final Pair<Integer, Integer> range) {
		super(category);
		this.range = range;
	}

	public int getMin() {
		return this.range.getX();
	}

	public int getMax() {
		return this.range.getY();
	}

	@Override
	public String toString() {
		return "RangeSettings [range =" + this.range + " " + super.toString() + "] ";
	}

}
