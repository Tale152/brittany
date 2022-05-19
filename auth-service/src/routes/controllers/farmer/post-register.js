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

const stringUtil = require('../util/stringUtil')
const Farmer = require('../../../mongoose/farmer')
const FarmerFactory = require('../../../mongoose/factories/farmer')

function areFarmerRegisterParametersValid(params){
    return stringUtil.isValidString(params.mail) &&
        stringUtil.isValidString(params.name) &&
        stringUtil.isValidString(params.surname) &&
        stringUtil.isValidString(params.password) &&
        stringUtil.isValidString(params.birthdate)
}

async function checkUniqueFarmerRegisterMail(req, res){
    Farmer.findOne({ mail: req.body.mail }).then(async result => {
        if(result !== null){
            res.status(406).json({err: "Mail not available"})
        } else {
            createNewFarmer(req, res)
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewFarmer(req, res){
    var newFarmer = FarmerFactory.createFarmer(
        req.body.name,
        req.body.surname,
        req.body.birthdate,
        req.body.mail,
        req.body.password,
        req.organizationId
    )
    saveNewFarmer(newFarmer, res)
}

async function saveNewFarmer(farmer, res){
    farmer.save().then(() => {
        res.status(201).json({id: farmer._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function farmerRegisterController(req, res){
    if(!areFarmerRegisterParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueFarmerRegisterMail(req, res)
    }
}

module.exports = {
    farmerRegisterController
}
