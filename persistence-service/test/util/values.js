const jwt = require('jsonwebtoken')

const agentTokenSecret = require('../../src/conf').agentTokenSecret

module.exports = {
    correctAgentToken: jwt.sign({}, agentTokenSecret),
    wrongToken: jwt.sign({}, "wrong"),
    idSettings: "61c099edd3c873c6030793b7",
}
