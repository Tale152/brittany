const express = require('express')
const router = express.Router()

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

router.post("/organization/create", (req, res) => {
    if(!areOrganizationCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        res.status(201).json({token: "TODO"})
    }
    
})

module.exports = router
