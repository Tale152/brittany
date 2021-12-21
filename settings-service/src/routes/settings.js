const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const agentTokenAuth = require('./controllers/agentTokenAuth')
const PostCreateSettings = require("./controllers/settings/post-create")
const GetListSettings = require("./controllers/settings/get-list")
const GetLatestSettings = require("./controllers/settings/get-latest")

router.post("/settings/create", farmerTokenAuth.verifyToken, PostCreateSettings.createSettingsController)

router.get("/settings/list", farmerTokenAuth.verifyToken, GetListSettings.listSettingsController)

router.get("/settings/latest", agentTokenAuth.verifyToken, GetLatestSettings.latestSettingsController)

module.exports = router
