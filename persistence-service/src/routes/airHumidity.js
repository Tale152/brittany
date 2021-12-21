const express = require('express')
const router = express.Router()

const agentTokenAuth = require('./controllers/agentTokenAuth')
const farmerTokenAuth = require('./controllers/farmerTokenAuth')

const PostAirHumidityRegister = require("./controllers/airHumidity/post-register")
const GetAirHumidityLatest = require("./controllers/airHumidity/get-latest")
const GetAirHumidityList = require("./controllers/airHumidity/get-list")

router.post("/airHumidity/register", agentTokenAuth.verifyToken, PostAirHumidityRegister.airHumidityRegisterController)

router.get("/airHumidity/latest", agentTokenAuth.verifyToken, GetAirHumidityLatest.airHumidityLatestController)

router.get("/airHumidity/list", farmerTokenAuth.verifyToken, GetAirHumidityList.airHumidityListController)

module.exports = router
