const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const PostCreateEnvironment = require("./controllers/environment/post-create")

router.post("/environment/create", tokenAuth.verifyToken, PostCreateEnvironment.createEnvironmentController)

module.exports = router
