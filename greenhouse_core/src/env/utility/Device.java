package utility;

/**
 * A device is the main object present in the physical greenhouse, used to sample or to actuate operations.
 *
 */
public class Device {
	private final String id;
	private final String category;
	//TODO TD
	
	public Device(final String id, final String category) {
		this.id = id;
		this.category = category;
	}

	public String getId() {
		return id;
	}

	public String getCategory() {
		return category;
	}

	@Override
	public String toString() {
		return "Device [id=" + id + ", category=" + category + "]";
	}
	
}
