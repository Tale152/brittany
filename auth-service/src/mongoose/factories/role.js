const Role = require("../role")

function createRole(name) {
    return new Role({
        name: name
    })
}

module.exports = {createRole}
