const express = require('express')
const router = express.Router()

const farmerTokenAuth = require('./controllers/farmerTokenAuth')
const GetFarmerLogin = require("./controllers/farmer/get-login")
const PostFarmerRegister = require("./controllers/farmer/post-register")
const GetFarmerInfo = require("./controllers/farmer/get-info")
const GetFarmerList = require("./controllers/farmer/get-list")

router.get("/farmer/login", GetFarmerLogin.farmerLoginController)

router.post("/farmer/register", farmerTokenAuth.verifyToken, PostFarmerRegister.farmerRegisterController)

router.get("/farmer/info", farmerTokenAuth.verifyToken, GetFarmerInfo.farmerInfoController)

router.get("/farmer/list", farmerTokenAuth.verifyToken, GetFarmerList.farmerListController)

module.exports = router
