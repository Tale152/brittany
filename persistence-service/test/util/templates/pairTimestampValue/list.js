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
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctRegister.exec(
        registerRoute,
        {
            value: valueNewest,
            timestamp: dateNewest
        }
    )

    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.correctFarmerToken,
        200,
        (res) => {
            expect(res.body.list.length).toBe(2)
            expect(res.body.list[0].value).toBe(valueNewest)
        }
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
