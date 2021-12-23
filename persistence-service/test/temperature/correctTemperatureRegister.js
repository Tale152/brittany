const httpTest = require('../util/httpTest')
const values = require('../util/values')

module.exports.execute = async function(server, body){
    await httpTest.post(server, "/temperature/register", body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}
