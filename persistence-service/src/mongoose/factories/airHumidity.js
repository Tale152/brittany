const AirHumidity = require("../airHumidity")

function createAirHumidity(idSettings, timestamp, value) {
    return new AirHumidity({
        id_settings: idSettings,
        timestamp: timestamp,
        value: value,
    })
}

module.exports = {createAirHumidity}
