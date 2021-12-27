const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')
const correctRegister = require('./correctRegister')

module.exports.correctList = async function(registerRoute, retreiveRoute){
    const valueOldest = 42
    const dateOldest = new Date()
    const valueNewest = 7
    const dateNewest = new Date(dateOldest.getTime() + 60000)

    await correctRegister.exec(
        registerRoute,
        {
            id: values.idEnvironment,
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctRegister.exec(
        registerRoute,
        {
            id: values.idEnvironment,
            value: valueNewest,
            timestamp: dateNewest
        }
    )

    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idEnvironment
        },
        values.correctFarmerToken,
        200,
        (res) => {
            expect(res.body.list.length).toBe(2)
            expect(res.body.list[0].value).toBe(valueNewest)
        }
    )
}

module.exports.notExistingId = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idEnvironment
        },
        values.correctFarmerToken,
        200,
        (res) => expect(res.body.list.length).toBe(0)
    )
}

module.exports.wrongToken = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {
            id: values.idEnvironment
        },
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
