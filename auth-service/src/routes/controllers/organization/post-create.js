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

const farmerTokenSecret = require('../../../conf').farmerTokenSecret
const stringUtil = require('../util/stringUtil')
const Organization = require('../../../mongoose/organization')
const OrganizationFactory = require('../../../mongoose/factories/organization')
const Farmer = require('../../../mongoose/farmer')
const FarmerFactory = require('../../../mongoose/factories/farmer')

function areOrganizationCreateParametersValid(params){
    return stringUtil.isValidString(params.organizationName) &&
        stringUtil.isValidString(params.mail) &&
        stringUtil.isValidString(params.name) &&
        stringUtil.isValidString(params.surname) &&
        stringUtil.isValidString(params.password) &&
        stringUtil.isValidString(params.birthdate)
}

async function checkUniqueOrganizationCreateParameters(req, res){
    Organization.findOne({ name: req.body.organizationName }).then(async result => {
        if(result !== null){
            res.status(406).json({err: "Organization name not available"})
        } else {
            Farmer.findOne({ mail: req.body.mail }).then(async result => {
                if(result !== null){
                    res.status(406).json({err: "Mail not available"})
                } else {
                    createNewOrganization(req, res)
                }
            }).catch(err => {
                res.status(500).json({err: err.toString()})
            })
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewOrganization(req, res){
    var newOrganization = OrganizationFactory.createOrganization(req.body.organizationName)
    var newFarmerOwner = FarmerFactory.createFarmer(
        req.body.name,
        req.body.surname,
        req.body.birthdate,
        req.body.mail,
        req.body.password,
        newOrganization._id
    )
    saveNewOrganization(newOrganization, newFarmerOwner, res)
}

async function deleteOrganization(id, res, error){
    Organization.deleteOne({ _id: id }).then(() => {
        res.status(500).json({err: error})
    }).catch(err => {
        deleteOrganization(id, res, error)
    })
}

async function saveNewOrganization(organization, farmer, res){
    organization.save().then(() => {
        farmer.save().then(() => {
            var payload = {
                farmerId: farmer._id.toString(),
                organizationId: organization._id.toString()
            }
            res.status(201).json({
                token: jwt.sign(payload, farmerTokenSecret)
            })
        }).catch(err => {
            deleteOrganization(organization._id, res, err.toString())
        })
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createOrganizationController(req, res){
    if(!areOrganizationCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueOrganizationCreateParameters(req, res)
    }
}

module.exports = {
    createOrganizationController
}
