const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')

async function correctRegister(registerRoute, body){
    await httpTest.post(server, registerRoute, body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}

module.exports.correctList = async function(registerRoute, retreiveRoute){
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
            id: values.idSettings
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
            id: values.idSettings
        },
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
