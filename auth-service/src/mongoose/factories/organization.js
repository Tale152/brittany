const Organization = require("../organization")

function createOrganization(name) {
    return new Organization({
        name: name
    })
}

module.exports = {createOrganization}
