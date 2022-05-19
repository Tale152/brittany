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
const ObjectId = require('mongoose').Types.ObjectId

const Organization = require('../../../mongoose/organization')
const Greenhouse = require('../../../mongoose/greenhouse')
const Environment = require('../../../mongoose/environment')
const agentTokenSecret = require('../../../conf').agentTokenSecret
const stringUtil = require('../util/stringUtil')

function areAgentLoginParametersValid(params){
    return stringUtil.isValidString(params.organizationName) && 
        stringUtil.isValidString(params.greenhouseName) &&
        stringUtil.isValidString(params.environmentName) &&
        stringUtil.isValidString(params.environmentPassword)
}

function tryOrganization(req, res){
    Organization.findOne({ name: req.query.organizationName }).then(async organization => {
        if(organization !== null){
            tryGreenhouse(req, res, organization)
        } else {
            res.status(401).json({err: "Invalid credentials"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

function tryGreenhouse(req, res, organization){
    Greenhouse
        .findOne({
            name: req.query.greenhouseName,
            id_organization: new ObjectId(organization._id.toString())
        })
        .then(async greenhouse => {
            if(greenhouse !== null){
                tryEnvironment(req, res, greenhouse)
            } else {
                res.status(401).json({err: "Invalid credentials"})
            }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

function tryEnvironment(req, res, greenhouse){
    Environment
        .findOne({ 
            name: req.query.environmentName,
            id_greenhouse: new ObjectId(greenhouse._id.toString())
        })
        .then(async environment => {
            if(environment !== null){
                bcrypt.compare(
                    req.query.environmentPassword,
                    environment.password,
                    async (err, result) => {
                        if (err) {
                            res.status(500).json({err: err.toString()})
                        } else if (result === true) {
                            var payload = {
                                environmentId: environment._id.toString()
                            }
                            res.status(200).json({
                                token: jwt.sign(payload, agentTokenSecret)
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

async function loginAgentController(req, res){
    if(areAgentLoginParametersValid(req.query)){
        tryOrganization(req, res)
    } else {
        res.status(406).json({err: "Invalid parameters"})
    }
}

module.exports = {
    loginAgentController
}
