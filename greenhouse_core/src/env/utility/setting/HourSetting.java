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

package utility.setting;

import java.time.LocalTime;

/**
 * HourSetting is a specific kind of Setting.
 * An HourSetting has a category, taken from its parent class,
 * and it has a starting time and and ending time, defining a 
 * time range.
 * This can be used when the setting are based on time.
 */
public class HourSetting extends Setting {
	
	private final LocalTime fromTime;
	private final LocalTime toTime;
	
	/**
	 * Constructor of HourSetting.
	 * 
	 * @param category the category that the setting is going to regulate.
	 * @param fromTime the starting time of the setting.
	 * @param toTime   the end time of the setting.
	 */
	public HourSetting(final String category, final LocalTime fromTime, final LocalTime toTime) {
		super(category);
		this.fromTime = fromTime;
		this.toTime = toTime;
	}

	/**
	 * An HourSetting has an initial time, which is used to know
	 * when that specific setting has to be applied.
	 * 
	 * @return the starting time of the HourSetting.
	 */
	public LocalTime getFromTime() {
		return fromTime;
	}

	/**
	 * An HourSetting has an ending time, which is used
	 * to know when that specific setting has to 
	 * be stopped to be applied.
	 * 
	 * @return the ending time of the HourSetting.
	 */
	public LocalTime getToTime() {
		return toTime;
	}

	@Override
	public String toString() {
		return "HourSetting [fromTime=" + fromTime + ", toTime=" + toTime + " " + super.toString() +  "]";
	}

}
