#include <Arduino.h>
#include <WifiController.h>

#ifndef WIFI_SSID
#define WIFI_SSID ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif

WifiController wifi;

void onWifiEvent(const WifiController::Event& event, void*) {
  if (event.type == WifiController::EventType::Connected) {
    const WifiController::Snapshot snapshot = wifi.snapshot();
    Serial.print(F("Connected to "));
    Serial.println(snapshot.wifiSsid);
  }
}

void setup() {
  Serial.begin(115200);

  WifiController::Config config;
  config.deviceId = "esp-connectivity-wifi";
  config.staSsid = WIFI_SSID;
  config.staPassword = WIFI_PASSWORD;
  config.apSsid = "EspConnectivity-Setup";
  config.apIp = WifiController::Ipv4Address(192, 168, 4, 1);
  wifi.begin(config, onWifiEvent, nullptr);
}

void loop() {
  wifi.tick();
}
