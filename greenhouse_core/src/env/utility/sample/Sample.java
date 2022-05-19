/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package utility.sample;

/**
 * Sample is a class used to contain the sample retrieved from
 * a component, keeping track of the category of the component,
 * the time when the sample was taken and the value of that sample.
 */
public class Sample {
    
    private final String category;
    private final String samplingTime;
    private final int value;

    /**
     * Constructor to create a Sample.
     * 
     * @param category     the category of the Sample, which define the type of component
     *                     that retrieved that sample.
     * @param samplingTime the time when the sample has been retrieved.
     * @param value        the value of the sample retrieved.
     */
    public Sample(final String category, final String samplingTime, final int value) {
        this.category = category;
        this.samplingTime = samplingTime;
        this.value = value;
    }

    /**
     * A Sample has a category which is the same of the Component
     * that retrieved that Sample.
     * 
     * @return the category of the Sample.
     */
    public String getCategory() {
        return this.category;
    }

    /**
     * A Sample has a time when the sample has been retrieved by 
     * the Component.
     * 
     * @return the time when the sample has been retrieved.
     */
    public String getSamplingTime() {
        return this.samplingTime;
    }

    /**
     * A Sample has a value that is the value retrieved from the 
     * Component, so from a physical sensor.
     * 
     * @return the value of the Sample.
     */
    public int getValue() {
        return this.value;
    }

    @Override
	public String toString() {
		return "Sample [category=" + category + ", samplingTime=" + samplingTime + ", value=" + value + "]";
	}
    
}
