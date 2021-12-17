const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const GetFarmerLogin = require("./controllers/farmer/get-login")
const PostFarmerRegister = require("./controllers/farmer/post-register")
const GetFarmerInfo = require("./controllers/farmer/get-info")
const GetFarmerList = require("./controllers/farmer/get-list")

router.get("/farmer/login", GetFarmerLogin.farmerLoginController)

router.post("/farmer/register", tokenAuth.verifyToken, PostFarmerRegister.farmerRegisterController)

router.get("/farmer/info", tokenAuth.verifyToken, GetFarmerInfo.farmerInfoController)

router.get("/farmer/list", tokenAuth.verifyToken, GetFarmerList.farmerListController)

module.exports = router
