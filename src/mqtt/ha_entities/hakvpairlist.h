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

#include <stddef.h>

class HAKVPairList {
protected:
  const char* key;
  const char* value;
  HAKVPairList* next;

public:
  HAKVPairList(const char* key, const char* value);
  void append(const char* key, const char* value = NULL);
  inline const char* getKey() { return key; }
  inline const char* getValue() { return value; }
  inline HAKVPairList* getNext() { return next; }
};
