const db = require('../util/db')
const timestampValueTests = require('../util/templates/pairTimestampValue/register')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const route = "/airHumidity/register"

test("Correct Air Humidity registration", async () => {
    await timestampValueTests.correctRegister(route)
})

test("Wrong token on Air Humidity registration", async () => {
    await timestampValueTests.wrongToken(route)
})

test("Missing body fields on Air Humidity registration", async () => {
    await timestampValueTests.missingBodyFields(route)
})

test("Body value not numeric on Air Humidity registration", async () => {
    await timestampValueTests.bodyValueNotNumeric(route)
})
