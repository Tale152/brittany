const express = require('express')
const router = express.Router()

const agentTokenAuth = require('./controllers/agentTokenAuth')

const PostTemperatureRegister = require("./controllers/temperature/post-register")

router.post("/temperature/register", agentTokenAuth.verifyToken, PostTemperatureRegister.temperatureRegisterController)

module.exports = router
