const express = require('express')
const router = express.Router()

const Role = require('../mongoose/role')
const Organization = require('../mongoose/organization')
const OrganizationFactory = require('../mongoose/factories/organization')
const Farmer = require('../mongoose/farmer')
const FarmerFactory = require('../mongoose/factories/farmer')

function isValidString(str){
    return str !== null && str !== undefined && str.trim() !== ""
}

function areOrganizationCreateParametersValid(params){
    return isValidString(params.organizationName) &&
        isValidString(params.mail) &&
        isValidString(params.name) &&
        isValidString(params.surname) &&
        isValidString(params.password) &&
        isValidString(params.birthdate)
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
                res.status(500).json({err: err})
            })
        }
    }).catch(err => {
        res.status(500).json({err: err})
    })
}

async function createNewOrganization(req, res){
    Role.findOne({ name: "Owner" }).then(async ownerRole => {
        if(ownerRole === null){
            res.status(500).json({err: "Cannot find Owner role"})
        } else {
            var newOrganization = OrganizationFactory.createOrganization(req.body.organizationName)
            var newFarmerOwner = FarmerFactory.createFarmer(
                req.body.name,
                req.body.surname,
                req.body.birthdate,
                req.body.mail,
                req.body.password,
                ownerRole._id,
                newOrganization._id
            )
            res.status(201).json({token: "TODO"})
        }
    }).catch(err => {
        res.status(500).json({err: err})
    })
}

router.post("/organization/create", (req, res) => {
    if(!areOrganizationCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueOrganizationCreateParameters(req, res)
    }
})

module.exports = router
