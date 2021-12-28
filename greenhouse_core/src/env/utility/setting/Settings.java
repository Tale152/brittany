package utility.setting;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Optional;

import utility.Pair;

public class Settings {
	
	private final String id;
	private final Date creationDate;
	private List<Setting> settings;
	
	public Settings(final String id, final Date creationDate) {
		this.id = id;
		this.creationDate = creationDate;
		this.settings = new ArrayList<>();
	}
	
	public void createSetting(final String category, final Pair<Integer, Integer> range) {
		if (isCategoryUnique(category)) {
			System.err.println("A setting for this category already exist.");
		} else {
			this.settings.add(new RangeSetting(category, range));
		}	
	}
	
	public void createSetting(final String category, final LocalTime fromTime, final LocalTime toTime) {
		if (isCategoryUnique(category)) {
			System.err.println("A setting for this category already exist.");
		} else {
			this.settings.add(new HourSetting(category, fromTime, toTime));
		}
	}
	
	private boolean isCategoryUnique(final String category) {
		return this.settings.stream().filter(s -> s.getCategory().equals(category)).findAny().isPresent();
	}
	
	public List<Setting> getSettings(){
		return new ArrayList<>(this.settings);
	}
	
	public Optional<Setting> getSetting(final String category) {
		return this.settings.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}

	public String getId() {
		return this.id;
	}
	
	public Date getCreationDate() {
		return this.creationDate;
	}

	@Override
	public String toString() {
		return "Settings [id=" + id + ", creationDate=" + creationDate + ", settings=" + settings + "]";
	}
		
}
