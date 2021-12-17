const Organization = require("../greenhouse")

function createGreenhouse(name) {
    return new Organization({
        name: name,
        environments: []
    })
}

module.exports = {createGreenhouse}
