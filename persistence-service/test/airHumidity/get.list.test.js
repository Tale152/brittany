const db = require('../util/db')
const listTests = require('../util/templates/pairTimestampValue/list')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/airHumidity/register"
const listRoute = "/airHumidity/list"

test("Retreiving correct Air Humidity list", async () => {
    await listTests.correctList(registerRoute, listRoute)
})

test("Not existing Settings id for Air Humidity list", async () => {
    await listTests.notExistingId(listRoute)
})

test("Wrong token for Air Humidity list", async () => {
    await listTests.wrongToken(listRoute)
})
