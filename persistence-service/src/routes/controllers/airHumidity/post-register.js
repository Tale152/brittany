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
const numberUtil = require('../util/numberUtil')
const AirHumidityFactory = require('../../../mongoose/factories/airHumidity')

function areAirHumidityRegisterParametersValid(params){
    return stringUtil.isValidString(params.timestamp) &&
        numberUtil.isValidNumber(params.value)
}

async function createNewAirHumidity(req, res){
    var newAirHumidity = AirHumidityFactory.createAirHumidity(
        req.environmentId,
        req.body.timestamp,
        req.body.value
    )
    saveNewAirHumidity(newAirHumidity, res)
}

async function saveNewAirHumidity(airHumidity, res){
    airHumidity.save().then(() => {
        res.status(201).json({id: airHumidity._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function airHumidityRegisterController(req, res){
    if(!areAirHumidityRegisterParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        createNewAirHumidity(req, res)
    }
}

module.exports = {
    airHumidityRegisterController
}
