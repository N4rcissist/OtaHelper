#include "OtaHelper.h"

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Arduino.h>
#include <map>
// Initialize OTA and Wi-Fi connections
void OtaHelper::start(const char* ssid, const char* password, const char* hostName, const char* hostPassword, int port, int baudRate) {
    Serial.begin(baudRate);
    Serial.println("Loading system...");

    connectWifi( ssid, password);
    setupOTA(port, hostName, hostPassword);
    Serial.println("OTA Ready");
}
// Handle OTA updates
void OtaHelper::handle() {
    ArduinoOTA.handle();
}
// Connect to Wi-Fi
void OtaHelper::connectWifi(const char* ssid, const char* password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Error with Wifi, restarting...");
        delay(5000);
        ESP.restart();
    }
    Serial.println("Connected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}
// Setup OTA functionality with defined callbacks and error handling
void OtaHelper::setupOTA(int port, const char* hostName, const char* hostPassword) {
    ArduinoOTA.setPort(port);
    ArduinoOTA.setHostname(hostName);
    ArduinoOTA.setPassword(hostPassword);

// OTA Callbacks
    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        } else {
            type = "filesystem";
        }

        Serial.println("Programming started " + type);
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("\nFinishing");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });

    // Error messages for OTA
      std::map<ota_error_t, const char*> errorMessages = {
      {OTA_AUTH_ERROR, "Auth Failed"},
      {OTA_BEGIN_ERROR, "Begin Failed"},
      {OTA_CONNECT_ERROR, "Connect Failed"},
      {OTA_RECEIVE_ERROR, "Receive Failed"},
      {OTA_END_ERROR, "Failed"}
       };

    ArduinoOTA.onError([&](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);

        if (errorMessages.find(error) != errorMessages.end()) {
            Serial.println(errorMessages[error]);
        } else {
            Serial.println("Unknown error");
        }
    });

    ArduinoOTA.begin();
}
