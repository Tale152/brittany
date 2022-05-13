package utility.setting;

/**
 * Setting is the father class of [[utility.setting.HourSetting]] and
 * [[utility.setting.RangeSetting]], extracting their common trait,
 * which is the category.
 */
public class Setting {
	
	private final String category;
	
	/**
	 * Constructor of Setting.
	 * 
	 * @param category the category that the setting regulates.
	 */
	public Setting(final String category) {
		this.category = category;
	}

	/**
	 * A Setting has a category that specifies the category of
	 * samples that it regulates.
	 * 
	 * @return the category of the setting.
	 */
	public String getCategory() {
		return this.category;
	}

	@Override
	public String toString() {
		return "Setting [category=" + category + "]";
	}

}
