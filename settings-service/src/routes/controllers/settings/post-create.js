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
const SettingsFactory = require('../../../mongoose/factories/settings')

function isBetween(val, min, max){
    return numberUtil.isValidNumber(val) &&
    Number.parseFloat(val) >= Number.parseFloat(min) &&
    Number.parseFloat(val) < Number.parseFloat(max)
}

function isLightValid(light){
    if(light !== undefined){
        return isBetween(light.fromH, 0, 24) &&
            isBetween(light.toH, 0, 24) &&
            isBetween(light.fromM, 0, 60) &&
            isBetween(light.toM, 0, 60)
    }
    return true
}
function isRangeFieldValid(field){
    if(field !== undefined){
        return numberUtil.isValidNumber(field.min) && 
            numberUtil.isValidNumber(field.max) &&
            Number.parseFloat(field.min) <= Number.parseFloat(field.max)
    }
    return true
}

function areSettingsCreateParametersValid(params){
    if(stringUtil.isValidString(params.idEnvironment) && stringUtil.isValidString(params.expires)){
        return isRangeFieldValid(params.temperature) && isRangeFieldValid(params.airHumidity) && isLightValid(params.light)
    }
    return false
}

async function createNewSettings(req, res){
    var newSettings = SettingsFactory.createSettings(
        req.body.idEnvironment,
        new Date(),
        req.body.expires,
        true
    )
    if(req.body.temperature !== undefined){
        newSettings.data.temperature = req.body.temperature
    }
    if(req.body.airHumidity !== undefined){
        newSettings.data.airHumidity = req.body.airHumidity
    }
    if(req.body.light !== undefined){
        newSettings.data.light = req.body.light
    }
    saveNewSettings(newSettings, res)
}

async function saveNewSettings(settings, res){
    settings.save().then(() => {
        res.status(201).json({id: settings._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createSettingsController(req, res){
    if(!areSettingsCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        createNewSettings(req, res)
    }
}

module.exports = {
    createSettingsController
}
