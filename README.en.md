# EspConnectivity

[Русская версия](README.md)

`EspConnectivity` is an Arduino library package for ESP8266 and ESP32 projects
that need predictable Wi-Fi provisioning, PlatformIO OTA listener control, and
Home Assistant MQTT lifecycle management.

## Components

- `WifiController.h` provides non-blocking STA connection campaigns and a
  fallback configuration AP.
- `OtaController.h` owns the PlatformIO/ArduinoOTA listener lifecycle.
- `MqttController.h` provides deferred MQTT connection, reconnect, and
  disconnect-barrier handling for `HAMQTTController` and `PubSubClient`.
- `HaMqttEntities.h` exposes the bundled Home Assistant discovery entities.

The package supports Arduino on ESP8266 and ESP32. Define `USE_OTA` to compile
and use `OtaController`; define `USE_MQTT` to compile and use
`MqttController`. `WifiController` is always available.

## Installation

Until Registry publication, use the Git dependency in `platformio.ini`:

```ini
lib_deps =
  https://github.com/ilyasshafigin/espconnectivity.git#v0.1.0
```

After publication, use the Registry package:

```ini
lib_deps =
  ilyasshafigin/EspConnectivity@^0.1.0
```

`MqttController` is intentionally an adapter for the bundled
`HaMqttEntities`/`HAMQTTController` and `hmueller01/pubsubclient3@3.3.1`; it is
not a generic MQTT client lifecycle wrapper.

See [`examples/`](examples) for credential-free Wi-Fi, OTA, and MQTT sketches.
Set credentials through build flags, `platformio.local.ini`, or another local
configuration mechanism; do not commit them.

## License and attribution

The original Wi-Fi, OTA, and MQTT controller code is licensed under
GPL-3.0-or-later; the complete license text is in
[`LICENSE`](LICENSE). `HaMqttEntities` is forked material from
[paulino/ha-mqtt-entities](https://github.com/paulino/ha-mqtt-entities),
copyright Paulino Ruiz de Clavijo Vázquez, and remains Apache-2.0 licensed.
Its complete Apache-2.0 text is in
[`LICENSES/Apache-2.0.txt`](LICENSES/Apache-2.0.txt); provenance and changes
are documented in [`docs/ha-mqtt-entities.md`](docs/ha-mqtt-entities.md). See
[`NOTICE`](NOTICE) for the distribution notice.
