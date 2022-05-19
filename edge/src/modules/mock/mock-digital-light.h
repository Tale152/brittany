/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef BRITTANY_MAIN_MOCK_DIGITAL_LIGHT

#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "mock-digital-light/modules/MockDigitalLightModule.h"

Edge* edge() {
    MockDigitalLightHw* light0 = new MockDigitalLightHw("0");
    MockDigitalLightHw* light1 = new MockDigitalLightHw("1");
    std::list<MockDigitalLightHw*> lights = std::list<MockDigitalLightHw*>({light0, light1});
    std::list<Module*> modules;
    modules.push_back(new MockDigitalLightModule(lights));
    return new Edge("Mock Digital Light Edge", modules);
}

#endif