# HaMqttEntities provenance

`EspConnectivity` includes a derivative implementation of
[paulino/ha-mqtt-entities](https://github.com/paulino/ha-mqtt-entities), based
on upstream version 1.0.12.

The original work is copyright (c) Paulino Ruiz de Clavijo Vázquez
(`<pruiz@us.es>`) and is licensed under Apache-2.0. Its complete license text
is retained in [`../LICENSES/Apache-2.0.txt`](../LICENSES/Apache-2.0.txt).

## Changes in this implementation

- Adds `HALight`, a Home Assistant MQTT light entity with brightness, effect,
  RGB command, and RGB state support.
- Adds `HATime`, a Home Assistant MQTT time entity with `HH:MM` state
  normalization.
- Replaces the global `HAMQTT` instance with a caller-owned
  `HAMQTTController` and a bounded entity registry.
- Adds contextual command callbacks and corrected state publishing.
- Makes `HADevice` passive; the controller owns availability and MQTT
  lifecycle.
- Adds cooperative discovery and state synchronization with bounded retry
  behavior after publish failures.
- Hardens command parsing and entity state handling so only fully valid
  payloads reach application callbacks.

Prominent notices in `src/mqtt/ha_entities/` identify the derivative files.
The `NOTICE` file at the repository root contains the distribution notice.
