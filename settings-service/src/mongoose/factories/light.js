const Light = require("../light")

function createLight(idSettings, fromH, fromM, toH, toM) {
    return new Light({
        id_settings: idSettings,
        fromH: fromH,
        fromM: fromM,
        toH: toH,
        toM: toM
    })
}

module.exports = {createLight}
