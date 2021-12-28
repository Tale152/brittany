package utility;

/**
 * A device is the main object present in the physical greenhouse, used to sample or to actuate operations.
 *
 */
public class Device {
	private final String id;
	private final String role;
	//TODO TD
	
	public Device(final String id, final String role) {
		this.id = id;
		this.role = role;
	}

	public String getId() {
		return id;
	}

	public String getRole() {
		return role;
	}

	@Override
	public String toString() {
		return "Device [id=" + id + ", role=" + role + "]";
	}
	
}
