#include <Arduino.h>
#include <OtaController.h>
#include <WifiController.h>

#ifndef WIFI_SSID
#define WIFI_SSID ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif

WifiController wifi;
OtaController ota;

void onOtaEvent(const OtaController::Event& event, void*) {
  if (event.type == OtaController::EventType::Start) Serial.println(F("OTA update started"));
  if (event.type == OtaController::EventType::End) Serial.println(F("OTA update completed"));
}

void setup() {
  Serial.begin(115200);

  WifiController::Config wifiConfig;
  wifiConfig.deviceId = "esp-connectivity-ota";
  wifiConfig.staSsid = WIFI_SSID;
  wifiConfig.staPassword = WIFI_PASSWORD;
  wifiConfig.apSsid = "EspConnectivity-Setup";
  wifiConfig.apIp = WifiController::Ipv4Address(192, 168, 4, 1);
  wifi.begin(wifiConfig, nullptr, nullptr);

  const OtaController::Config otaConfig{
    "esp-connectivity-ota",
    0,
    true,
    nullptr,
    nullptr,
  };
  ota.begin(otaConfig, onOtaEvent, nullptr);
}

void loop() {
  wifi.tick();
  ota.tick(wifi.staConnected());
}
