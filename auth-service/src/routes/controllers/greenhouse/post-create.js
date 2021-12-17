const stringUtil = require('../util/stringUtil')
const Organization = require('../../../mongoose/organization')
const OrganizationFactory = require('../../../mongoose/factories/organization')
const Greenhouse = require('../../../mongoose/greenhouse')
const GreenhouseFactory = require('../../../mongoose/factories/greenhouse')

function areGreenhouseCreateParametersValid(params){
    return stringUtil.isValidString(params.name)
}

async function checkUniqueGreenhouseCreateName(req, res){
    Organization.findById(req.organizationId).then(async organization => {
        if(organization !== null){
            if(organization.greenhouses.find(g => g.name === req.body.name) === undefined){
                createNewGreenhouse(req, res, organization)
            } else {
                res.status(406).json({err: "Greenhouse name already in use"})
            }
        } else {
            res.status(404).json({err: "organization not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createNewGreenhouse(req, res, organization){
    var newGreenhouse = GreenhouseFactory.createGreenhouse(
        req.body.name
    )
    organization.greenhouses.push(newGreenhouse)
    saveNewGreenhouse(newGreenhouse, organization, res)
}

async function saveNewGreenhouse(greenhouse, organization, res){
    organization.save().then(() => {
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
