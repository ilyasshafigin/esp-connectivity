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

class HAText : public HAEntity {
protected:
  static const char* const component;

  bool dirty;
  char* state;
  unsigned int maxSize;

public:
  HAText(const char* unique_id, const char* name, HADevice& device, unsigned int max_size);
  HAText(const char* unique_id, const char* name, unsigned int max_size);

  inline bool isDirty() { return this->dirty; };
  const char* getState() { return this->state; };
  void setState(const char* state);

  void onConnect(PubSubClient* client);
  bool onReceivedTopic(PubSubClient* client, byte* payload, unsigned int length);
  bool sendState(PubSubClient* client) override;
};
