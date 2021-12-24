package utility;

/**
 * A device is the main object present in the physical greenhouse, used to sample or to actuate operations.
 * @author teemo
 *
 */
public class Device {
	private final String id;
	private final String role;
	private int currentValue;
	//TODO TD
	
	public Device(final String id, final String role) {
		this.id = id;
		this.role = role;
		this.currentValue = 0;
	}

	public String getId() {
		return id;
	}

	public String getRole() {
		return role;
	}

	public int getCurrentValue() {
		return currentValue;
	}

	public void setCurrentValue(int currentValue) {
		this.currentValue = currentValue;
	}

	@Override
	public String toString() {
		return "Device [id=" + id + ", role=" + role + ", currentValue=" + currentValue + "]";
	}
	
}
