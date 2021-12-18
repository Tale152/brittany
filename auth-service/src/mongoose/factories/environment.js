const Environment = require("../environment")

function createEnvironment(idGreenhouse, name, password) {
    return new Environment({
        id_greenhouse: idGreenhouse,
        name: name,
        password: password
    })
}

module.exports = {createEnvironment}
