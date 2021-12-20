const jwt = require('jsonwebtoken')

const Farmer = require('../../../mongoose/farmer')
const farmerTokenSecret = require('../../../conf').farmerTokenSecret
const stringUtil = require('../util/stringUtil')

function areFarmerLoginParametersValid(params){
    return stringUtil.isValidString(params.mail) && stringUtil.isValidString(params.password)
}

function tryLogin(req, res){
    Farmer.findOne({ mail: req.query.mail, password: req.query.password }).then(async result => {
        if(result !== null){
            var payload = {
                farmerId: result._id.toString(),
                organizationId: result.id_organization.toString()
            }
            res.status(201).json({
                token: jwt.sign(payload, farmerTokenSecret)
            })
        } else {
            res.status(401).json({err: "Invalid credentials"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function farmerLoginController(req, res){
    if(areFarmerLoginParametersValid(req.query)){
        tryLogin(req, res)
    } else {
        res.status(406).json({err: "Invalid parameters"})
    }
}

module.exports = {
    farmerLoginController
}
