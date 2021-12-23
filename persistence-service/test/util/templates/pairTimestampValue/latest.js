const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')

async function correctTemperatureRegister(body){
    await httpTest.post(server, "/temperature/register", body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}

module.exports.latestOneValue = async function(route){
    const value = 42
    await correctTemperatureRegister(
        {
            id: values.idSettings,
            value: value,
            timestamp: new Date()
        }
    )
    await httpTest.get(
        server,
        route,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(value)
    )
}

module.exports.latestMultipleValues = async function(route){
    const valueOldest = 42
    const dateOldest = new Date()
    const valueNewest = 7
    const dateNewest = new Date(dateOldest.getTime() + 60000)

    await correctTemperatureRegister(
        {
            id: values.idSettings,
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctTemperatureRegister(
        {
            id: values.idSettings,
            value: valueNewest,
            timestamp: dateNewest
        }
    )

    await httpTest.get(
        server,
        route,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
}

module.exports.notExistingId = async function(route){
    await httpTest.get(
        server,
        route,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        404,
        (res) => {/* does nothing */}
    )
}

module.exports.wrongToken = async function(route){
    await httpTest.get(
        server,
        route,
        {
            id: values.idSettings
        },
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
