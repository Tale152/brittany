const Temperature = require("../temperature")

function createTemperature(idSettings, timestamp, value) {
    return new Temperature({
        id_settings: idSettings,
        timestamp: timestamp,
        value: value,
    })
}

module.exports = {createTemperature}
