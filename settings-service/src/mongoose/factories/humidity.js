const Humidity = require("../humidity")

function createHumidity(idSettings, min, max) {
    return new Humidity({
        id_settings: idSettings,
        min: min,
        max: max
    })
}

module.exports = {createHumidity}
