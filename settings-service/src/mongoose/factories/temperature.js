const Temperature = require("../temperature")

function createTemperature(idSettings, min, max) {
    return new Temperature({
        id_settings: idSettings,
        min: min,
        max: max
    })
}

module.exports = {createTemperature}
