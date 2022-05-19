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
