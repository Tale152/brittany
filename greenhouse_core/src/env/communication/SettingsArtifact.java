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

// CArtAgO artifact code for project greenhouse_core

package communication;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalTime;
import java.util.Date;
import java.util.Optional;
import java.util.TimeZone;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import cartago.*;
import okhttp3.HttpUrl;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import utility.Pair;
import utility.setting.Settings;

/**
 * SettingsArtifact is an Artifact used to communicate with the settings service
 * outside the greenhouse. It is the Artifact used to retrieve settings for the
 * greenhouse.
 */
public class SettingsArtifact extends Artifact {

	private final static String UTC_FORMAT = "yyyy-MM-dd'T'HH:mm:ss";

	private OkHttpClient client;

	void init() {
		this.client = new OkHttpClient();
	}

	/**
	 * Operation used to get the current settings from the settings service that are decided
	 * by the user.
	 * @param token it is the authentication token which is used to correctly ask for information to the server.
	 */
	@OPERATION
	void getSettings(final String token) {
		try (Response response = client.newCall(getSettingsRequest(token)).execute()) {
			if (!response.isSuccessful()) {
				// settings are empty
				defineObsProperty("settings", Optional.empty());
			} else {
				JsonObject settingsObject = JsonParser.parseString(response.body().string()).getAsJsonObject();
				if (settingsObject.has("_id") && settingsObject.has("created")) {
					Settings settings = new Settings(
						settingsObject.get("_id").getAsString(), 
						getSettingsCreationDate(settingsObject));
					if (settingsObject.has("data")) {
						JsonObject dataObject = settingsObject.get("data").getAsJsonObject();
						createRangeSetting(dataObject, settings, "temperature");
						createRangeSetting(dataObject, settings, "airHumidity");
						createHourSetting(dataObject, settings, "light");
					}
					defineObsProperty("settings", Optional.of(settings));
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Utility method used to create the HTTP request in order to ask for the current settings to the server.
	 * @param token it is the authentication token which is used to correctly ask for information to the server.
	 * @return the HTTP request ready to be lauched.
	 */
	private Request getSettingsRequest(final String token) {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(System.getenv("SETTINGS_SERVICE_URL")).newBuilder();
		String url = urlBuilder.build().toString();
		return new Request.Builder().addHeader("token", token).url(url).build();
	}

	/**
	 * Utility method used to extract from the json object the date of creating of the retrieved
	 * settings from the server.
	 * @param settingsObject the json object with all the settings returned by the server.
	 * @return the date of creationg of the settings retrieved.
	 */
	private Date getSettingsCreationDate(final JsonObject settingsObject) {
		SimpleDateFormat dataFormatter = new SimpleDateFormat(UTC_FORMAT);
		dataFormatter.setTimeZone(TimeZone.getTimeZone("UTC"));
		Date creationDate = new Date();
		try {
			creationDate = dataFormatter.parse(settingsObject.get("created").getAsString());
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return creationDate;	
	}

	/**
	 * Utility method used to create a setting of a specific category which has a min and max value.
	 * @param dataObject the json object with all the settings.
	 * @param settings the current settings retrieved from the json object.
	 * @param category the category of the settings wanted.
	 */
	private void createRangeSetting(final JsonObject dataObject, final Settings settings, final String category) {
		if (dataObject.has(category)) {
			JsonObject temperature = dataObject.get(category).getAsJsonObject();
			settings.createSetting(category,
					new Pair<>(temperature.get("min").getAsInt(), temperature.get("max").getAsInt()));
		}
	}

	/**
	 * Utility method used to create a setting of a specific category which depends on a time range.
	 * @param dataObject the json object with all the settings.
	 * @param settings the current settings retrieved from the json object.
	 * @param category the cateogry of the settings wanted.
	 */
	private void createHourSetting(final JsonObject dataObject, final Settings settings, final String category) {
		if (dataObject.has(category)) {
			JsonObject light = dataObject.get(category).getAsJsonObject();
			LocalTime fromTime = LocalTime.of(light.get("fromH").getAsInt(), light.get("fromM").getAsInt());
			LocalTime toTime = LocalTime.of(light.get("toH").getAsInt(), light.get("toM").getAsInt());
			settings.createSetting(category, fromTime, toTime);
		}
	}

}
