const server = require('../../src/server')
const db = require('../util/db')
const values = require('../util/values')
const httpTest = require('../util/httpTest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const active = true
const expires = new Date(new Date().getTime() + 60000)

const correctBody = {
    idEnvironment: values.idEnvironment,
    active: active,
    expires: expires
}

async function settingsCreate406(body){
    await settingsCreate(body, values.correctFarmerToken, 406, (res) => { expect(res.body).toHaveProperty("err") })
}

async function settingsCreate(body, token, code, then){
    await httpTest.post(server, "/settings/create", body, token, code, then)
}

test("Correct Settings creation", async () => {
    await settingsCreate(correctBody, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("id"))
})

test("Wrong token", async () => {
    await settingsCreate(correctBody, values.wrongToken, 401, (res) => { /* does nothing */})
})

test("Missing body fields", async () => {
    await settingsCreate406({
        active: active,
        expires: expires
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        expires: expires
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        active: active,
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        temperature: {
            min: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        temperature: {
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        airHumidity: {
            min: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        airHumidity: {
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromM: 30,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            fromM: 30,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            fromM: 30,
            toH: 5,
        }
    })
})

test("Wrong params type", async () => {
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        temperature: {
            min: "NaN",
            max: 1
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        temperature: {
            min: 0,
            max: "NaN",
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        airHumidity: {
            min: "NaN",
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        airHumidity: {
            min: 0,
            max: "NaN",
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: "NaN",
            fromM: 30,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            fromM: "NaN",
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            fromM: 30,
            toH: "NaN",
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        active: active,
        light: {
            fromH: 18,
            fromM: 30,
            toH: 5,
            toM: "NaN",
        }
    })
})
