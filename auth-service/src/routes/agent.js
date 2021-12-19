const express = require('express')
const router = express.Router()

const GetLoginAgent = require("./controllers/agent/get-login")

router.get("/agent/login", GetLoginAgent.loginAgentController)

module.exports = router
