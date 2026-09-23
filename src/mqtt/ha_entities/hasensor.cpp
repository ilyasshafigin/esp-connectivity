/*
 * Derived from HaMqttEntities
 * Copyright (c) Paulino Ruiz de Clavijo Vázquez.
 * Based on upstream version 1.0.12:
 * https://github.com/paulino/ha-mqtt-entities
 *
 * Modified by Ilyas Shafigin for EspConnectivity.
 * See third_party/HaMqttEntities/README.md for the modification summary.
 */

#include <Arduino.h>
#include <PubSubClient.h>
#include "hasensor.h"

const char* const HASensor::component PROGMEM = "sensor";

HASensor::HASensor(const char* unique_id, const char* name, const char* component)
  : HAEntity(unique_id, name, component) {
  this->dirty = false;
}

void HASensor::onConnect(PubSubClient* client) {
  char topic[HA_MAX_TOPIC_LENGTH], payload[HA_MAX_PAYLOAD_LENGTH];
  getConfigTopic(topic);
  getConfigPayload(payload, false, true);
  client->publish(topic, payload);
}
