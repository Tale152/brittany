const express = require('express')
const router = express.Router()

const agentTokenAuth = require('./controllers/agentTokenAuth')

const PostTemperatureRegister = require("./controllers/temperature/post-register")
const GetTemperatureLatest = require("./controllers/temperature/get-latest")

router.post("/temperature/register", agentTokenAuth.verifyToken, PostTemperatureRegister.temperatureRegisterController)

router.get("/temperature/latest", agentTokenAuth.verifyToken, GetTemperatureLatest.temperatureLatestController)

module.exports = router
