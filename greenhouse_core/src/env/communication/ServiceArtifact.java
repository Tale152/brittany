// CArtAgO artifact code for project greenhouse_core

package communication;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import cartago.*;
import okhttp3.HttpUrl;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

/**
 * ServiceArtifact is an Artifact used to communicate with all the services outside the greenhouse.
 * It is the Artifact used to retrieve settings for the greenhouse and it is used also to upload the data
 * registered by the sampling devices.
 *
 */
public class ServiceArtifact extends Artifact {

	private final static String LOGIN_FILE = "login.txt";
	private final static String AUTH_SERVICE = "http://localhost:81/agent/login";
	
	private OkHttpClient client;
	private List<String> loginData;

	void init() {
		this.loginData = new ArrayList<>();
		this.client = new OkHttpClient();
	}

	/**
	 * Operation used to retrieve the authentication token, in order to be able to communicate with the other
	 * services.
	 */
	@OPERATION void retrieveAuthenticationData() {
		try {
			File file = new File(LOGIN_FILE);
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String data = scanner.nextLine();
				this.loginData.add(data);
			}
			scanner.close();
			autheticate();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	@INTERNAL_OPERATION void autheticate() {
		HttpUrl.Builder urlBuilder = HttpUrl.parse(AUTH_SERVICE).newBuilder();
		urlBuilder.addQueryParameter("organizationName", this.loginData.get(0));
		urlBuilder.addQueryParameter("greenhouseName", this.loginData.get(1));
		urlBuilder.addQueryParameter("environmentName", this.loginData.get(2));
		urlBuilder.addQueryParameter("environmentPassword", this.loginData.get(3));
		String url = urlBuilder.build().toString();
		
		Request request = new Request.Builder()
                .url(url)
                .build();
		
		try (Response response = client.newCall(request).execute()) {
            if (!response.isSuccessful()) {
            	throw new IOException("Unexpected code " + response);
            }
            
            JsonObject tokenObject = JsonParser.parseString(response.body().string()).getAsJsonObject(); 
            
            if (tokenObject.has("token")) {
            	System.out.println("TOKEN:" + tokenObject.get("token"));
            	defineObsProperty("token", tokenObject.get("token").toString());
            } else {
            	throw new IllegalStateException("You did not received the token.");
            }
        } catch (IOException e) {
			e.printStackTrace();
		}
	}

}
