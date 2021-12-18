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
