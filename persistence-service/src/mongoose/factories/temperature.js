const Temperature = require("../temperature")

function createTemperature(idSettings, time, value) {
    return new Temperature({
        id_settings: idSettings,
        timestamp: timestamp,
        value: value,
    })
}

module.exports = {createTemperature}
