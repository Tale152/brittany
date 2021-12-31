#ifdef BRITTANY_MAIN_MOCK_DIGITAL_LIGHT

std::list<Module*> edge_modules() {
    MockDigitalLightHw* light0 = new MockDigitalLightHw("0", 0);
    MockDigitalLightHw* light1 = new MockDigitalLightHw("1", 1);
    std::list<MockDigitalLightHw*> lights = std::list<MockDigitalLightHw*>({light0, light1});
    std::list<Module*> modules;
    modules.push_back(new MockDigitalLightModule("light", lights));
    return modules;
}

#endif