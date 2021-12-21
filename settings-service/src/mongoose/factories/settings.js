const Settings = require("../settings")

function createSettings(idEnvironment, created, expires, active) {
    return new Settings({
        id_environment: idEnvironment,
        created: created,
        expires: expires,
        active: active,
        data: {}
    })
}

module.exports = {createSettings}
