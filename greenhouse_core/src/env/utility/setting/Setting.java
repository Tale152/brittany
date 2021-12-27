package utility.setting;

public class Setting {
	
	private final String category;
	
	public Setting(final String category) {
		this.category = category;
	}

	public String getCategory() {
		return this.category;
	}

	@Override
	public String toString() {
		return "Setting [category=" + category + "]";
	}

}
