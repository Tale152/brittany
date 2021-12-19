const Greenhouse = require("../greenhouse")

function createGreenhouse(idOrganization, name) {
    return new Greenhouse({
        id_organization: idOrganization,
        name: name
    })
}

module.exports = {createGreenhouse}
