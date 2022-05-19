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

const jwt = require('jsonwebtoken')
const bcrypt = require('bcryptjs')

const Farmer = require('../../../mongoose/farmer')
const farmerTokenSecret = require('../../../conf').farmerTokenSecret
const stringUtil = require('../util/stringUtil')

function areFarmerLoginParametersValid(params){
    return stringUtil.isValidString(params.mail) && stringUtil.isValidString(params.password)
}

function tryLogin(req, res){
    Farmer.findOne({ mail: req.query.mail }).then(async farmer => {
        if(farmer !== null){
            bcrypt.compare(
                req.query.password,
                farmer.password,
                async (err, result) => {
                    if (err) {
                        res.status(500).json({err: err.toString()})
                    } else if (result === true) {
                        var payload = {
                            farmerId: farmer._id.toString(),
                            organizationId: farmer.id_organization.toString()
                        }
                        res.status(200).json({
                            token: jwt.sign(payload, farmerTokenSecret)
                        })
                    } else {
                        res.status(401).json({err: "Invalid credentials"})
                    }
                }
            )
        } else {
            res.status(401).json({err: "Invalid credentials"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function farmerLoginController(req, res){
    if(areFarmerLoginParametersValid(req.query)){
        tryLogin(req, res)
    } else {
        res.status(406).json({err: "Invalid parameters"})
    }
}

module.exports = {
    farmerLoginController
}
