package communication;

import java.io.IOException;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import cartago.Artifact;
import cartago.OPERATION;
import okhttp3.HttpUrl;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

/**
 * AuthenticationArtifact is an Artifact used to communicate with the authentication 
 * service outside the greenhouse. It is the Artifact used to retrieve the token for the
 * greenhouse, which is used to communicate with the other services.
 */
public class AuthenticationArtifact extends Artifact {

	private OkHttpClient client;

	void init() {
		this.client = new OkHttpClient();
	}

    /**
	 * Operation used to retrieve the authentication token, in order to be able to
	 * communicate with the other services, sending the HTTP request to the authentication service.
	 */
	@OPERATION
	void retrieveAuthenticationData() {
		try (Response response = client.newCall(getAuthenticationRequest()).execute()) {
			if (!response.isSuccessful()) {
				throw new IOException("Unexpected code while retrieving TOKEN: " + response);
			}
			JsonObject tokeJsonObject = JsonParser.parseString(response.body().string()).getAsJsonObject();
			extractToken(tokeJsonObject);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

    /**
     * Method used to create the request used to ask to the authentication service for the authentication
     * token. In the request are also added the query parameters used for authenticate.
     * @return the HTTP request to send to the authentication service.
     */
    private Request getAuthenticationRequest() {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(System.getenv("AUTH_SERVICE_URL")).newBuilder();
		urlBuilder.addQueryParameter("organizationName", System.getenv("ORGANIZATION_NAME"));
		urlBuilder.addQueryParameter("greenhouseName", System.getenv("GREENHOUSE_NAME"));
		urlBuilder.addQueryParameter("environmentName", System.getenv("ENVIRONMENT_NAME"));
		urlBuilder.addQueryParameter("environmentPassword", System.getenv("ENVIRONMENT_PASSWORD"));
		String url = urlBuilder.build().toString();
		return new Request.Builder().url(url).build();
	}

    /**
     * Having the json object returned by the authentication token, retrieve it and create an 
     * observable property that can be seen by anyone who focus on this artifact.
     * @param tokeJsonObject the Json Object returned by the authentication service.
     */
	private void extractToken(final JsonObject tokeJsonObject) {
		if (tokeJsonObject.has("token")) {
			defineObsProperty("token", tokeJsonObject.get("token").getAsString());
		} else {
			throw new IllegalStateException("You have not received the token");
		}
	}
}
