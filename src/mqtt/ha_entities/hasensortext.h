/*
 * Derived from HaMqttEntities
 * Copyright (c) Paulino Ruiz de Clavijo Vázquez.
 * Based on upstream version 1.0.12:
 * https://github.com/paulino/ha-mqtt-entities
 *
 * Modified by Ilyas Shafigin for EspConnectivity.
 * See third_party/HaMqttEntities/README.md for the modification summary.
 */
#pragma once

#include "hasensor.h"

class PubSubClient;
class HADevice;

class HASensorText : public HASensor {
protected:
  char* state;
  int maxSize;

public:
  HASensorText(const char* unique_id, const char* name, HADevice& device, int max_size);
  HASensorText(const char* unique_id, const char* name, int max_size);

  const char* getState() { return this->state; };
  void setState(const char* state);
  bool onReceivedTopic(PubSubClient* client, byte* payload, unsigned int length) {
    (void)client;
    (void)payload;
    (void)length;
    return false;
  }

  bool sendState(PubSubClient* client) override;
};
