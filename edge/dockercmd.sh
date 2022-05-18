#!/bin/bash

rm src/wifi_secret.h
echo -e "#define WIFI_SSID \"${BRITTANY_WIFI_SSID}\"\n#define WIFI_PSWD \"${BRITTANY_WIFI_PSWD}"\" >> src/wifi_secret.h
pio run -e mock-temperature-humidity -t upload
