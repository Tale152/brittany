package communication;

import java.io.IOException;

import com.google.gson.JsonObject;

import cartago.Artifact;
import cartago.OPERATION;
import okhttp3.HttpUrl;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;
import utility.Sample;

public class PersistenceArtifact extends Artifact {

	private final static String PERSISTENCE_SERVICE_URL = "https://brittany-persistence-service.herokuapp.com:443/";
	private OkHttpClient client;

	void init() {
		this.client = new OkHttpClient();
	}

	@OPERATION
	void uploadPersistence(final Sample sample, final String token) {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(PERSISTENCE_SERVICE_URL + sample.getCategory() + "/register")
				.newBuilder();
		String url = urlBuilder.build().toString();

		JsonObject jsonSample = new JsonObject();
		jsonSample.addProperty("value", sample.getValue());
		jsonSample.addProperty("timestamp", sample.getSamplingTime());

		RequestBody body = RequestBody.create(jsonSample.toString(),
				MediaType.parse("application/json; charset=utf-8"));

		Request request = new Request.Builder()
				.addHeader("token", token)
				.url(url)
				.post(body)
				.build();

		try (Response response = client.newCall(request).execute()) {
			if (!response.isSuccessful()) {
				throw new IOException("Unexpected code " + response);
			} else {
				System.out.println(sample + " correcty uploaded");
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
