const db = require('../util/db')
const latestTests = require('../util/templates/pairTimestampValue/latest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const route = "/temperature/latest"

test("Retreiving with just one value for Temperature", async () => {
    await latestTests.latestOneValue(route)
})

test("Retreiving with multiple values for Temperature", async () => {
    await latestTests.latestMultipleValues(route)
})

test("Not existing Settings id for Temperature", async () => {
    await latestTests.notExistingId(route)
})

test("Wrong token for Temperature", async () => {
    await latestTests.wrongToken(route)
})
