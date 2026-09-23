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

#include "habutton.h"

const char *const HAButton::component PROGMEM = "button";

HAButton::HAButton(const char *unique_id, const char *name, HADevice& device):
    HAEntity(unique_id,name,component,&device) {
}
HAButton::HAButton(const char *unique_id, const char *name):
    HAEntity(unique_id,name,component) {
}

void HAButton::onConnect(PubSubClient * client){
    char topic[HA_MAX_TOPIC_LENGTH],payload[HA_MAX_PAYLOAD_LENGTH];
    getCommandTopic(topic);
    client->subscribe(topic);

    getConfigTopic(topic);
    getConfigPayload(payload,true,false);
    client->publish(topic,payload);
}
