#ifdef BRITTANY_MAIN_DHT22

std::list<Module*> edge_modules() {
    DHT22SensorHw* dht22 = new DHT22SensorHw("dht22", D5);
    std::list<DHT22SensorHw*> sensors = std::list<DHT22SensorHw*>({dht22});
    std::list<Module*> modules;
    modules.push_back(new DHT22Module("temp-hum", sensors));
    return modules;
}

#endif