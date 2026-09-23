#include <Arduino.h>
#include <HaMqttEntities.h>
#include <MqttController.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <WifiController.h>

#ifndef WIFI_SSID
#define WIFI_SSID ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif

#ifndef MQTT_HOST
#define MQTT_HOST ""
#endif

#ifndef MQTT_PORT
#define MQTT_PORT 1883
#endif

#ifndef MQTT_USER
#define MQTT_USER ""
#endif

#ifndef MQTT_PASSWORD
#define MQTT_PASSWORD ""
#endif

WifiController wifi;
WiFiClient transport;
PubSubClient mqttClient(transport);
HAMQTTController haController;
HADevice haDevice("esp-connectivity-example", "ESP Connectivity", "0.1.0", "EspConnectivity", "MQTT example");
HASensorNumeric uptime("_uptime", "Uptime", haDevice, "s", 0);
HAEntity* entities[] = {&uptime};

bool staConnected(void*) {
  return wifi.staConnected();
}

void abortTransport(void*) {
#if defined(ARDUINO_ARCH_ESP32)
  transport.stop();
#else
  transport.abort();
#endif
}

uint32_t currentTime(void*) {
  return millis();
}

MqttController mqtt(
  haController,
  mqttClient,
  MqttController::LinkHooks(nullptr, staConnected, abortTransport, currentTime)
);

void setup() {
  Serial.begin(115200);

  WifiController::Config wifiConfig;
  wifiConfig.deviceId = "esp-connectivity-mqtt";
  wifiConfig.staSsid = WIFI_SSID;
  wifiConfig.staPassword = WIFI_PASSWORD;
  wifiConfig.apSsid = "EspConnectivity-Setup";
  wifiConfig.apIp = WifiController::Ipv4Address(192, 168, 4, 1);
  wifi.begin(wifiConfig, nullptr, nullptr);

  bool haReady = haController.begin(mqttClient, entities, sizeof(entities) / sizeof(entities[0]));
  haReady = haReady && haController.addEntity(uptime) && haController.registrationComplete();
  mqtt.begin(MqttController::Config(MQTT_HOST, "esp-connectivity-example", MQTT_USER, MQTT_PASSWORD, MQTT_PORT), haReady);
}

void loop() {
  wifi.tick();
  mqtt.tick(millis());
  uptime.setState(millis() / 1000.0F);
}
