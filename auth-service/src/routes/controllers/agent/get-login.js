const jwt = require('jsonwebtoken')
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
    Organization.findOne({ name: req.body.organizationName }).then(async organization => {
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
            name: req.body.greenhouseName,
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
            name: req.body.environmentName,
            id_greenhouse: new ObjectId(greenhouse._id.toString()),
            password: req.body.environmentPassword
        })
        .then(async environment => {
            if(environment !== null){
                var payload = {
                    environmentId: environment._id.toString()
                }
                res.status(200).json({
                    token: jwt.sign(payload, agentTokenSecret)
                })
            } else {
                res.status(401).json({err: "Invalid credentials"})
            }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function loginAgentController(req, res){
    if(areAgentLoginParametersValid(req.body)){
        tryOrganization(req, res)
    } else {
        res.status(406).json({err: "Invalid parameters"})
    }
}

module.exports = {
    loginAgentController
}
