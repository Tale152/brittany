const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')
const correctRegister = require('./correctRegister')

const value = 42
const timestamp = new Date()

const correctBody = {
    id: values.idSettings,
    value: value,
    timestamp: timestamp
}

module.exports.correctRegister = async function(route){
    await correctRegister.exec(route, correctBody)
}

module.exports.wrongToken = async function(route){
    await httpTest.post(
        server,
        route,
        correctBody,
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}

module.exports.missingBodyFields = async function(route){
    await httpTest.post(
        server,
        route,
        {
            value: value,
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
    await httpTest.post(
        server,
        route,
        {
            id: values.idSettings,
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
    await httpTest.post(
        server,
        route,
        {
            id: values.idSettings,
            value: value
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
}

module.exports.bodyValueNotNumeric = async function(route){
    await httpTest.post(
        server,
        route,
        {
            id: values.idSettings,
            value: "not a number",
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => {/* does nothing */}
    )
}
