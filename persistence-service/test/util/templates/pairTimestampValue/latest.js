const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')

async function correctRegister(registerRoute, body){
    await httpTest.post(server, registerRoute, body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}

module.exports.latestOneValue = async function(registerRoute, retreiveRoute){
    const value = 42
    await correctRegister(
        registerRoute, 
        {
            id: values.idSettings,
            value: value,
            timestamp: new Date()
        }
    )
    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(value)
    )
}

module.exports.latestMultipleValues = async function(registerRoute, retreiveRoute){
    const valueOldest = 42
    const dateOldest = new Date()
    const valueNewest = 7
    const dateNewest = new Date(dateOldest.getTime() + 60000)

    await correctRegister(
        registerRoute,
        {
            id: values.idSettings,
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctRegister(
        registerRoute,
        {
            id: values.idSettings,
            value: valueNewest,
            timestamp: dateNewest
        }
    )

    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
}

module.exports.notExistingId = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        404,
        (res) => {/* does nothing */}
    )
}

module.exports.wrongToken = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idSettings
        },
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
