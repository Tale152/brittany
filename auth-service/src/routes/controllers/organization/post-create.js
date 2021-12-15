const jwt = require('jsonwebtoken')

const tokenSecret = require('../../../conf').tokenSecret
const stringUtil = require('../util/stringUtil')
const Role = require('../../../mongoose/role')
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
            saveNewOrganization(newOrganization, newFarmerOwner, res)
        }
    }).catch(err => {
        res.status(500).json({err: err})
    })
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
                token: jwt.sign(payload, tokenSecret)
            })
        }).catch(err => {
            deleteOrganization(organization._id, res, err)
        })
    }).catch(err => {
        res.status(500).json({err: err})
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
