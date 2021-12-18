const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const PostCreateEnvironment = require("./controllers/environment/post-create")
const GetListEnvironment = require("./controllers/environment/get-list")
const GetInfoEnvironment = require("./controllers/environment/get-info")

router.post("/environment/create", tokenAuth.verifyToken, PostCreateEnvironment.createEnvironmentController)

router.get("/environment/list", tokenAuth.verifyToken, GetListEnvironment.listEnvironmentController)

router.get("/environment/info", tokenAuth.verifyToken, GetInfoEnvironment.infoEnvironmentController)

module.exports = router
