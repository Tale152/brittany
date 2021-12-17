const Organization = require("../greenhouse")

function createEnvironment(name) {
    return new Organization({
        name: name
    })
}

module.exports = {createEnvironment}
