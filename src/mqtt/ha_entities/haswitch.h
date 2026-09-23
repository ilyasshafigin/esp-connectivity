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

#include "haentity.h"

class PubSubClient;
class HADevice;

class HASwitch : public HAEntity {
protected:
  static const char* const component;

  bool dirty;
  bool state;

public:
  HASwitch(const char* unique_id, const char* name, HADevice& device);
  HASwitch(const char* unique_id, const char* name);

  inline bool getState() { return state; };
  inline bool isDirty() { return dirty; };
  void setState(bool state);

  void onConnect(PubSubClient* client);
  bool onReceivedTopic(PubSubClient* client, byte* payload, unsigned int length);
  bool sendState(PubSubClient* client) override;
};
