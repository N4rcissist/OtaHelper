# OtaHelper Library

The ConnectOta library simplifies Over-the-Air (OTA) updates and Wi-Fi connection management for ESP32 and ESP8266 devices, enabling seamless wireless updates and effortless Wi-Fi configuration.

## Features

- **OTA Updates:** Perform firmware updates wirelessly without physical access to the device.
- **Easy Wi-Fi Connection:** Simplify Wi-Fi network setup and automatic reconnection.
- **Error Handling:** Comprehensive error handling for OTA and Wi-Fi connection issues.
- **mDNS Support:** Facilitate device discovery with multicast Domain Name System (mDNS).

## Usage

The library provides an easy-to-use interface for initializing OTA updates and managing Wi-Fi connections, streamlining the process for both ESP32 and ESP8266 platforms.

### Installation

#### Arduino Library Manager

1. Open Arduino IDE.
2. Go to `Sketch` -> `Include Library` -> `Manage Libraries...`.
3. Search for `OtaHelper`.
4. Click `Install`.

#### Manual Installation

1. Download the latest release from [GitHub](https://github.com/N4rcissist/OtaHelper).
2. In the Arduino IDE, go to `Sketch` -> `Include Library` -> `Add .ZIP Library...`.
3. Select the downloaded file and click `Open`.

## Example

```cpp
##include "OtaHelper.h"

// Instance of the ConnectOta class
OtaHelper otaInstance;

void setup() {
  // Initial system setup

  // ssid: Wi-Fi network name
  // password: Wi-Fi network password
  // hostName: Device name on the local network (for mDNS)
  // hostPassword: Password for OTA updates
  // port: Port for OTA updates
  // baudRate: Serial communication speed
  otaInstance.start("ssid", "password", "hostName", "hostPassword", 3232, 115200);
}

void loop() {
  // Continuously handle OTA updates
  otaInstance.handle();
}

```


## Contributing
Contributions are welcome! Feel free to open an issue or create a pull request for improvements or bug fixes.

## License

This library is licensed under the [MIT License](https://github.com/N4rcissist/OTA-Connection-Handler/blob/main/LICENSE.md).
