const Organization = require("../greenhouse")

function createEnvironment(name, password) {
    return new Organization({
        name: name,
        password: password
    })
}

module.exports = {createEnvironment}
