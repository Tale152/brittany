const jwt = require('jsonwebtoken')

module.exports = {
    correctAgentToken: jwt.sign({}, require('../../src/conf').agentTokenSecret),
    correctFarmerToken: jwt.sign({}, require('../../src/conf').farmerTokenSecret),
    wrongToken: jwt.sign({}, "wrong"),
    idSettings: "61c099edd3c873c6030793b7",
}
