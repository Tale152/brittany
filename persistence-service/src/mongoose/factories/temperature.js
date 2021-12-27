const Temperature = require("../temperature")

function createTemperature(idEnvironment, timestamp, value) {
    return new Temperature({
        id_environment: idEnvironment,
        timestamp: timestamp,
        value: value,
    })
}

module.exports = {createTemperature}
