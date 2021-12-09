const Temperature = require("../temperature")

function createTemperature(time, value) {
    return new Temperature({
        time: time,
        value: value,
    })
}

module.exports = {createTemperature}
