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
const Environment = require('../../../mongoose/environment')
const EnvironmentFactory = require('../../../mongoose/factories/environment')

function areEnvironmentCreateParametersValid(params){
    return stringUtil.isValidString(params.greenhouseId) &&
        stringUtil.isValidString(params.name) &&
        stringUtil.isValidString(params.password)
}

async function checkUniqueEnvironmentCreateName(req, res){
    Environment.find({ id_greenhouse: new ObjectId(req.body.greenhouseId) }).then(async environments => {
        if(environments.find(e => e.name === req.body.name) === undefined){
            createNewEnvironments(req, res)
        } else {
            res.status(406).json({err: "Environment name already in use"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewEnvironments(req, res){
    var newEnvironment = EnvironmentFactory.createEnvironment(
        req.body.greenhouseId,
        req.body.name,
        req.body.password
    )
    saveNewEnvironment(newEnvironment, res)
}

async function saveNewEnvironment(environment, res){
    environment.save().then(() => {
        res.status(201).json({id: environment._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createEnvironmentController(req, res){
    if(!areEnvironmentCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueEnvironmentCreateName(req, res)
    }
}

module.exports = {
    createEnvironmentController
}
