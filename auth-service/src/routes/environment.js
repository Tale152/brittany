const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const PostCreateEnvironment = require("./controllers/environment/post-create")
const GetListEnvironment = require("./controllers/environment/get-list")

router.post("/environment/create", farmerTokenAuth.verifyToken, PostCreateEnvironment.createEnvironmentController)

router.get("/environment/list", farmerTokenAuth.verifyToken, GetListEnvironment.listEnvironmentController)

module.exports = router
