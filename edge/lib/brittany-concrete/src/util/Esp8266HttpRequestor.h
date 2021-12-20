#ifndef BRITTANY_ESP_8266_HTTP_REQUESTOR_H
#define BRITTANY_ESP_8266_HTTP_REQUESTOR_H

#include <Arduino.h>
#include <string>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <tuple>
#include <WiFiClient.h>

class Esp8266HttpRequestor {

private:

    int httpResponseCode;
    std::string response;

    void resetFields() {
        httpResponseCode = 0;
        response = "Request failed.";
    }

    std::tuple<int, std::string> makeHttpRequest(
        std::string address,
        std::string content_type,
        std::string content,
        bool isGet
    ) {
        if(WiFi.status() == WL_CONNECTED) {
            WiFiClient wifiClient;
            HTTPClient http;
            http.begin(wifiClient, address.c_str());
            http.addHeader("Content-Type", content_type.c_str());
            if(isGet){
                httpResponseCode = http.GET();
            } else {
                httpResponseCode = http.POST(content.c_str());
            }
            if(httpResponseCode > 0) {
                response = http.getString().c_str();     
            }
            Serial.println("RESPONSE CODE:" + httpResponseCode);
            Serial.println((String)"RESPONSE CONTENT: " + response.c_str());
            http.end();
        }
        return std::tuple<int, std::string>{httpResponseCode, response};
    }

public:

    Esp8266HttpRequestor() {
        resetFields();
    }

    std::tuple<int, std::string> makeHttpPostRequest(std::string address, std::string content_type, std::string content) {
        return makeHttpRequest(address, content_type, content, false);
    }

    std::tuple<int, std::string> makeHttpGetRequest(std::string address, std::string content_type) {
        return makeHttpRequest(address, content_type, "", true);
    }

};

#endif //BRITTANY_ESP_8266_HTTP_REQUESTOR_H