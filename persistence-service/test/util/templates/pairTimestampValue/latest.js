const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')
const correctRegister = require('./correctRegister')

module.exports.latestOneValue = async function(registerRoute, retreiveRoute){
    const value = 42
    await correctRegister.exec(
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
        {},
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

    await correctRegister.exec(
        registerRoute,
        {
            id: values.idSettings,
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctRegister.exec(
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
        {},
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
}

module.exports.notExistingId = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.correctAgentToken,
        404,
        (res) => {/* does nothing */}
    )
}

module.exports.wrongToken = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
