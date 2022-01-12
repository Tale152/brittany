#ifndef MOCK_HUMIDITY_SENSOR_HW_H
#define MOCK_HUMIDITY_SENSOR_HW_H

#include "hw/interfaces/sensors/HumiditySensorHwInterface.h"
#include "util.h"

#define MOCK_MAX_HUMIDITY 100

/**
 * @brief Mock Implementation of a humidity sensor hw.
 */
class MockHumiditySensorHw : public HumiditySensorHwInterface {

public:

    /**
     * @brief Construct a new MockHumiditySensorHw object.
     * 
     * @param id the hw id.
     */
    MockHumiditySensorHw(std::string id) : HumiditySensorHwInterface(id) { };

    std::optional<float> humidity() {
        return std::optional<float>(random(0, MOCK_MAX_HUMIDITY));
    }

};
#endif //MOCK_HUMIDITY_SENSOR_HW_H
