# EspConnectivity

[English version](README.en.md)

`EspConnectivity` — Arduino-библиотека для проектов на ESP8266 и ESP32, где
нужны предсказуемое подключение Wi-Fi, управление listener'ом PlatformIO OTA и
жизненным циклом MQTT для Home Assistant.

## Компоненты

- `WifiController.h` запускает неблокирующие попытки подключения к STA и
  поднимает резервную точку доступа для настройки.
- `OtaController.h` управляет жизненным циклом listener'а PlatformIO/ArduinoOTA.
- `MqttController.h` отложенно подключает и переподключает MQTT, а также
  выполняет disconnect-barrier для `HAMQTTController` и `PubSubClient`.
- `HaMqttEntities.h` предоставляет встроенные сущности Home Assistant Discovery.

Пакет поддерживает Arduino на ESP8266 и ESP32. Определите `USE_OTA`, чтобы
собрать и использовать `OtaController`, либо `USE_MQTT` — для
`MqttController`. `WifiController` доступен всегда.

## Установка

До публикации в Registry подключайте библиотеку из Git в `platformio.ini`:

```ini
lib_deps =
  https://github.com/ilyasshafigin/espconnectivity.git#v0.1.0
```

После публикации используйте пакет из Registry:

```ini
lib_deps =
  ilyasshafigin/EspConnectivity@^0.1.0
```

`MqttController` намеренно является адаптером для встроенных
`HaMqttEntities`/`HAMQTTController` и `hmueller01/pubsubclient3@3.3.1`; это не
универсальный контроллер жизненного цикла MQTT-клиента.

Смотрите примеры без учётных данных в [`examples/`](examples). Передавайте
учётные данные через build flags, `platformio.local.ini` или другой локальный
механизм конфигурации; не добавляйте их в репозиторий.

## Лицензия и атрибуция

Оригинальный код Wi-Fi-, OTA- и MQTT-контроллеров распространяется под
GPL-3.0-or-later; полный текст находится в [`LICENSE`](LICENSE).
`HaMqttEntities` основан на
[paulino/ha-mqtt-entities](https://github.com/paulino/ha-mqtt-entities),
copyright Paulino Ruiz de Clavijo Vázquez, и остаётся под лицензией Apache-2.0.
Полный текст Apache-2.0 находится в
[`LICENSES/Apache-2.0.txt`](LICENSES/Apache-2.0.txt), а происхождение и
изменения описаны в [`docs/ha-mqtt-entities.md`](docs/ha-mqtt-entities.md).
Уведомление для распространения находится в [`NOTICE`](NOTICE).
