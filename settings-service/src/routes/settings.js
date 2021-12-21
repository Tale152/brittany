const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const PostCreateSettings = require("./controllers/settings/post-create")

router.post("/settings/create", farmerTokenAuth.verifyToken, PostCreateSettings.createSettingsController)

module.exports = router
