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

const ObjectId = require('mongoose').Types.ObjectId

const stringUtil = require('../util/stringUtil')
const Greenhouse = require('../../../mongoose/greenhouse')
const GreenhouseFactory = require('../../../mongoose/factories/greenhouse')

function areGreenhouseCreateParametersValid(params){
    return stringUtil.isValidString(params.name)
}

async function checkUniqueGreenhouseCreateName(req, res){
    Greenhouse.find({ id_organization: new ObjectId(req.organizationId) }).then(async greenhouses => {
        if(greenhouses.find(g => g.name === req.body.name) === undefined){
            createNewGreenhouse(req, res)
        } else {
            res.status(406).json({err: "Greenhouse name already in use"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewGreenhouse(req, res){
    var newGreenhouse = GreenhouseFactory.createGreenhouse(
        req.organizationId,
        req.body.name
    )
    saveNewGreenhouse(newGreenhouse, res)
}

async function saveNewGreenhouse(greenhouse, res){
    greenhouse.save().then(() => {
        res.status(201).json({id: greenhouse._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createGreenhouseController(req, res){
    if(!areGreenhouseCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueGreenhouseCreateName(req, res)
    }
}

module.exports = {
    createGreenhouseController
}
