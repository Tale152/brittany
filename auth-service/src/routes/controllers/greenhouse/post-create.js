const ObjectId = require('mongoose').Types.ObjectId

const stringUtil = require('../util/stringUtil')
const Greenhouse = require('../../../mongoose/greenhouse')
const GreenhouseFactory = require('../../../mongoose/factories/greenhouse')

function areGreenhouseCreateParametersValid(params){
    return stringUtil.isValidString(params.name)
}

async function checkUniqueGreenhouseCreateName(req, res){
    Greenhouse.find({ id_organization: new ObjectId(req.organizationId) }).then(async greenhouses => {
        if(greenhouses.find(g => g.name === req.body.name) === undefined){
            createNewGreenhouse(req, res)
        } else {
            res.status(406).json({err: "Greenhouse name already in use"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewGreenhouse(req, res){
    var newGreenhouse = GreenhouseFactory.createGreenhouse(
        req.organizationId,
        req.body.name
    )
    saveNewGreenhouse(newGreenhouse, res)
}

async function saveNewGreenhouse(greenhouse, res){
    greenhouse.save().then(() => {
        res.status(201).json({id: greenhouse._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createGreenhouseController(req, res){
    if(!areGreenhouseCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        checkUniqueGreenhouseCreateName(req, res)
    }
}

module.exports = {
    createGreenhouseController
}
