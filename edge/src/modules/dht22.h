#ifdef BRITTANY_MAIN_DHT22

Edge* edge() {
    DHT22SensorHw* dht22 = new DHT22SensorHw("dht22", D5);
    std::list<DHT22SensorHw*> sensors = std::list<DHT22SensorHw*>({dht22});
    std::list<Module*> modules;
    modules.push_back(new DHT22Module("temp-hum", sensors));
    return new Edge("Temperature and Humidity Edge", modules);
}

#endif