const express = require('express')
const router = express.Router()

const agentTokenAuth = require('./controllers/agentTokenAuth')
const farmerTokenAuth = require('./controllers/farmerTokenAuth')

const PostTemperatureRegister = require("./controllers/temperature/post-register")
const GetTemperatureLatest = require("./controllers/temperature/get-latest")
const GetTemperatureList = require("./controllers/temperature/get-list")

router.post("/temperature/register", agentTokenAuth.verifyToken, PostTemperatureRegister.temperatureRegisterController)

router.get("/temperature/latest", agentTokenAuth.verifyToken, GetTemperatureLatest.temperatureLatestController)

router.get("/temperature/list", farmerTokenAuth.verifyToken, GetTemperatureList.temperatureListController)

module.exports = router
