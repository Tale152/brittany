package utility;

public class Sample {
    
    private final String category;
    private final String samplingTime;
    private final int value;

    public Sample(final String category, final String samplingTime, final int value) {
        this.category = category;
        this.samplingTime = samplingTime;
        this.value = value;
    }

    public String getCategory() {
        return this.category;
    }

    public String getSamplingTime() {
        return this.samplingTime;
    }

    public int getValue() {
        return this.value;
    }

    @Override
	public String toString() {
		return "Sample [category=" + category + ", samplingTime=" + samplingTime + ", value=" + value + "]";
	}
    
}
