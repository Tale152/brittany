const express = require('express')
const router = express.Router()

const Organization = require('../mongoose/organization')
const Farmer = require('../mongoose/farmer')

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
    Organization.findOne({ name: req.body.organizationName}).then(async result => {
        if(result !== null){
            res.status(406).json({err: "Organization name not available"})
        } else {
            Farmer.findOne({ mail: req.body.mail }).then(async result => {
                if(result !== null){
                    res.status(406).json({err: "Mail not available"})
                } else {
                    res.status(201).json({token: "TODO"})
                }
            }).catch(err => {
                res.status(500).json({err: err})
            })
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
