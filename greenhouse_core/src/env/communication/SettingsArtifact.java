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
 * ServiceArtifact is an Artifact used to communicate with all the services
 * outside the greenhouse. It is the Artifact used to retrieve settings for the
 * greenhouse and it is used also to upload the data registered by the sampling
 * devices.
 *
 */
public class SettingsArtifact extends Artifact {

	private final static String UTC_FORMAT = "yyyy-MM-dd'T'HH:mm:ss";
	private final static String SETTINGS_SERVICE_URL = "http://localhost:82/settings/latest";

	private OkHttpClient client;

	void init() {
		this.client = new OkHttpClient();
	}

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

	private Request getSettingsRequest(final String token) {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(SETTINGS_SERVICE_URL).newBuilder();
		String url = urlBuilder.build().toString();
		return new Request.Builder().addHeader("token", token).url(url).build();
	}

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

	private void createRangeSetting(final JsonObject dataObject, Settings settings, final String category) {
		if (dataObject.has(category)) {
			JsonObject temperature = dataObject.get(category).getAsJsonObject();
			settings.createSetting(category,
					new Pair<>(temperature.get("min").getAsInt(), temperature.get("max").getAsInt()));
		}
	}

	private void createHourSetting(final JsonObject dataObject, Settings settings, final String category) {
		if (dataObject.has(category)) {
			JsonObject light = dataObject.get(category).getAsJsonObject();
			LocalTime fromTime = LocalTime.of(light.get("fromH").getAsInt(), light.get("fromM").getAsInt());
			LocalTime toTime = LocalTime.of(light.get("toH").getAsInt(), light.get("toM").getAsInt());
			settings.createSetting(category, fromTime, toTime);
		}
	}

}
