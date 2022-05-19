/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
