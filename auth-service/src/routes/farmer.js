const express = require('express')
const router = express.Router()

const GetFarmerLogin = require("./controllers/farmer/get-login")

router.get("/farmer/login", GetFarmerLogin.farmerLoginController)



module.exports = router
