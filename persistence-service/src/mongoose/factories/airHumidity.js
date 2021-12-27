const AirHumidity = require("../airHumidity")

function createAirHumidity(idEnvironment, timestamp, value) {
    return new AirHumidity({
        id_environment: idEnvironment,
        timestamp: timestamp,
        value: value,
    })
}

module.exports = {createAirHumidity}
