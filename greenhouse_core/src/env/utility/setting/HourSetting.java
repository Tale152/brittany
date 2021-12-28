package utility.setting;

import java.time.LocalTime;

public class HourSetting extends Setting {
	
	private final LocalTime fromTime;
	private final LocalTime toTime;
	
	public HourSetting(final String category, final LocalTime fromTime, final LocalTime toTime) {
		super(category);
		this.fromTime = fromTime;
		this.toTime = toTime;
	}

	public LocalTime getFromTime() {
		return fromTime;
	}

	public LocalTime getToTime() {
		return toTime;
	}

	@Override
	public String toString() {
		return "HourSetting [fromTime=" + fromTime + ", toTime=" + toTime + " " + super.toString() +  "]";
	}

}
