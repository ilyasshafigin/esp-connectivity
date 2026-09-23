/*
 * New derivative component for the HaMqttEntities-based implementation.
 * Based on Apache-2.0-licensed HaMqttEntities, upstream version 1.0.12:
 * https://github.com/paulino/ha-mqtt-entities
 *
 * Copyright (c) 2026 Ilyas Shafigin.
 * See third_party/HaMqttEntities/README.md for the modification summary.
 */
#pragma once

#ifdef USE_MQTT

#include "haentity.h"

class PubSubClient;
class HADevice;

class HATime : public HAEntity {
protected:
  static const char* const component;

  bool dirty;
  char state[6];

  void (*commandCallback)(const char* timeState);

public:
  HATime(const char* unique_id, const char* name, HADevice& device);
  HATime(const char* unique_id, const char* name);

  inline bool isDirty() override { return dirty; }
  inline const char* getState() const { return state; }

  void setState(const char* timeState);

  void onCommand(void (*callback)(const char* timeState));

  void onConnect(PubSubClient* client) override;
  bool onReceivedTopic(PubSubClient* client, byte* payload, unsigned int length) override;
  bool sendState(PubSubClient* client) override;

  bool dispatchCommand(PubSubClient* client, const char* topic, byte* payload, unsigned int length);
};

#endif
