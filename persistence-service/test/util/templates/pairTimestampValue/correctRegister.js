const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')

module.exports.exec = async function(registerRoute, body){
    await httpTest.post(server, registerRoute, body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}
