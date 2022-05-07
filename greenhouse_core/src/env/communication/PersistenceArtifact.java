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
import utility.sample.Sample;

/**
 * PersistenceArtifact is an Artifact used to upload samples to an external
 * service.
 * When a sample is out of a specific delta, 
 * then the sample is going to be uploaded.
 */
public class PersistenceArtifact extends Artifact {

	private final static String PERSISTENCE_SERVICE_URL = "https://brittany-persistence-service.herokuapp.com:443/";

	private OkHttpClient client;

	void init() {
		this.client = new OkHttpClient();
	}

	/**
	 * Operation used to send an HTTP request to the service in order to upload the
	 * sample retrieved.
	 * 
	 * @param sample the sample that has to be uploaded because it is out of the
	 *               delta specified.
	 * @param token  the token used to correctly send the HTTP request to the
	 *               service.
	 */
	@OPERATION
	void uploadPersistence(final Sample sample, final String token) {
		try (Response response = client.newCall(getUploadRequest(sample, token)).execute()) {
			if (!response.isSuccessful()) {
				throw new IOException("Unexpected code " + response);
			} else {
				System.out.println(sample + " correcty uploaded");
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Utility method used to build the HTTP request that is going to be send to the
	 * service.
	 * It contains tha value and the timestamp of the sample in the body and the
	 * token in the head of the request.
	 * 
	 * @param sample the sample that has been registered to be out of a specified
	 *               delta and that need to be uploaded.
	 * @param token  the token used to correctly send the HTTP request to the
	 *               service.
	 * @return the HTTP request to send to the persistence service.
	 */
	private Request getUploadRequest(final Sample sample, final String token) {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(PERSISTENCE_SERVICE_URL + sample.getCategory() + "/register").newBuilder();
		String url = urlBuilder.build().toString();

		JsonObject jsonSample = new JsonObject();
		jsonSample.addProperty("value", sample.getValue());
		jsonSample.addProperty("timestamp", sample.getSamplingTime());

		RequestBody body = RequestBody.create(jsonSample.toString(),
				MediaType.parse("application/json; charset=utf-8"));

		return new Request.Builder().addHeader("token", token).url(url).post(body).build();
	}

}
