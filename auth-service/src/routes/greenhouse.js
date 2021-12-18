const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const PostCreateGreenhouse = require("./controllers/greenhouse/post-create")
const GetListGreenhouse = require("./controllers/greenhouse/get-list")

router.post("/greenhouse/create", farmerTokenAuth.verifyToken, PostCreateGreenhouse.createGreenhouseController)

router.get("/greenhouse/list", farmerTokenAuth.verifyToken, GetListGreenhouse.listGreenhouseController)

module.exports = router
