const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const PostCreateGreenhouse = require("./controllers/greenhouse/post-create")
const GetListGreenhouse = require("./controllers/greenhouse/get-list")

router.post("/greenhouse/create", tokenAuth.verifyToken, PostCreateGreenhouse.createGreenhouseController)

router.get("/greenhouse/list", tokenAuth.verifyToken, GetListGreenhouse.listGreenhouseController)

module.exports = router
