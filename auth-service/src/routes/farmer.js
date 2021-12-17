const express = require('express')
const router = express.Router()

const tokenAuth = require('./controllers/tokenAuth')
const GetFarmerLogin = require("./controllers/farmer/get-login")
const PostFarmerRegister = require("./controllers/farmer/post-register")

router.get("/farmer/login", GetFarmerLogin.farmerLoginController)

router.post("/farmer/register", tokenAuth.verifyToken, PostFarmerRegister.farmerRegisterController)

module.exports = router
