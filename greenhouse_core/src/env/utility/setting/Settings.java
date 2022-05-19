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
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Optional;

import utility.Pair;

/**
 * Settings is a class used to contain all the settings of the greenhouse,
 * which can be [[utility.setting.HourSetting]] and/or [[utility.setting.RangeSetting]].
 * The settings have also a creation date and an id.
 */
public class Settings {
	
	private final String id;
	private final Date creationDate;
	private List<Setting> settings;
	
	/**
	 * Constructor of Settings.
	 * 
	 * @param id 		   the identification of the current settings of the greenhouse.
	 * @param creationDate the creation date of the settings.
	 */
	public Settings(final String id, final Date creationDate) {
		this.id = id;
		this.creationDate = creationDate;
		this.settings = new ArrayList<>();
	}
	
	/**
	 * Mehod used to create a [[utility.setting.Setting]], given the
	 * category and a pair of values, that are the range of value accepted
	 * for a specific category of samples.
	 * 
	 * @param category the category that the setting regulates.
	 * @param range	   a pair of values that is the range of values accepted.
	 */
	public void createSetting(final String category, final Pair<Integer, Integer> range) {
		if (isCategoryUnique(category)) {
			System.err.println("A setting for this category already exist.");
		} else {
			this.settings.add(new RangeSetting(category, range));
		}	
	}
	
	/**
	 * Method used to create a [[utilituy.setting.Setting]], given the
	 * category the initial time and the ending time of validity of
	 * the setting.
	 * 
	 * @param category the category that the setting regulates.
	 * @param fromTime the starting time of the validity of the setting.
	 * @param toTime   the ending time of validity of the setting.
	 */
	public void createSetting(final String category, final LocalTime fromTime, final LocalTime toTime) {
		if (isCategoryUnique(category)) {
			System.err.println("A setting for this category already exist.");
		} else {
			this.settings.add(new HourSetting(category, fromTime, toTime));
		}
	}
	
	/**
	 * Utility method used to check if exists another setting for the same category
	 * in the list of settings.
	 * 
	 * @param category the category of the setting searched in the list.
	 * @return true if it exists another setting with the category specified,
	 * false otherwise.
	 */
	private boolean isCategoryUnique(final String category) {
		return this.settings.stream().filter(s -> s.getCategory().equals(category)).findAny().isPresent();
	}
	
	/**
	 * Get a safe copy of the list of settings present.
	 * 
	 * @return a safe copy of the list of settings.
	 */
	public List<Setting> getSettings(){
		return new ArrayList<>(this.settings);
	}

	/**
	 * A setting has an unique identifier.
	 * 
	 * @return the unique id of the setting.
	 */
	public String getId() {
		return this.id;
	}
	
	/**
	 * A setting has a creation date, which is the date
	 * the user created it.
	 * 
	 * @return the creation date of the setting.
	 */
	public Date getCreationDate() {
		return this.creationDate;
	}
	
	/**
	 * Method used to get a setting based on the category specified.
	 * 
	 * @param category the category of the setting searched.
	 * @return an optional of the setting of the category specified if found,
	 * an optional of empty otherwise.
	 */
	public Optional<Setting> getSetting(final String category) {
		return this.settings.stream().filter(s -> s.getCategory().equals(category)).findFirst();
	}

	@Override
	public String toString() {
		return "Settings [id=" + id + ", creationDate=" + creationDate + ", settings=" + settings + "]";
	}
		
}
