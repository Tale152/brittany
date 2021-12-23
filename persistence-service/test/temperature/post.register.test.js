const db = require('../util/db')
const timestampValueTests = require('../util/templates/pairTimestampValue/register')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const route = "/temperature/register"

test("Correct Temperature registration", async () => {
    await timestampValueTests.correctRegister(route)
})

test("Wrong token on Temperature registration", async () => {
    await timestampValueTests.wrongToken(route)
})

test("Missing body fields on Temperature registration", async () => {
    await timestampValueTests.missingBodyFields(route)
})

test("Body value not numeric on Temperature registration", async () => {
    await timestampValueTests.bodyValueNotNumeric(route)
})
