const db = require('../util/db')
const listTests = require('../util/templates/pairTimestampValue/list')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/temperature/register"
const listRoute = "/temperature/list"

test("Retreiving correct Temperature list", async () => {
    await listTests.correctList(registerRoute, listRoute)
})

test("Not existing Settings id for Temperature list", async () => {
    await listTests.notExistingId(listRoute)
})

test("Wrong token for Temperature list", async () => {
    await listTests.wrongToken(listRoute)
})
