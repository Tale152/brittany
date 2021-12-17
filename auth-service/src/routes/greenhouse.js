const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const PostCreateGreenhouse = require("./controllers/greenhouse/post-create")

router.post("/greenhouse/create", tokenAuth.verifyToken, PostCreateGreenhouse.createGreenhouseController)

module.exports = router
