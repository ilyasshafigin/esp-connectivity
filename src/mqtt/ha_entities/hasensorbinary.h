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

class HASensorBinary : public HASensor {
protected:
  static const char* const component;
  bool state;

public:
  HASensorBinary(const char* unique_id, const char* name);
  HASensorBinary(const char* unique_id, const char* name, HADevice& device);

  bool getState() { return this->state; };
  void setState(bool state);

  bool sendState(PubSubClient* client) override;
};
