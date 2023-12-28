#ifndef OtaHelper_h
#define OtaHelper_h

#include <Arduino.h>

class OtaHelper {
public:
    void start(const char* ssid, const char* password, const char* hostName, const char* hostPassword, int port, int baudRate);
    void handle();

private:
    void connectWifi(const char* ssid, const char* password);
    void setupOTA(int port, const char* hostName, const char* hostPassword);
};

#endif
