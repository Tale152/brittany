const stringUtil = require('../util/stringUtil')
const numberUtil = require('../util/numberUtil')
const TemperatureFactory = require('../../../mongoose/factories/temperature')

function areTemperatureRegisterParametersValid(params){
    return stringUtil.isValidString(params.timestamp) &&
        numberUtil.isValidNumber(params.value)
}

async function createNewTemperature(req, res){
    var newTemperature = TemperatureFactory.createTemperature(
        req.environmentId,
        req.body.timestamp,
        req.body.value
    )
    saveNewTemperature(newTemperature, res)
}

async function saveNewTemperature(temperature, res){
    temperature.save().then(() => {
        res.status(201).json({id: temperature._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function temperatureRegisterController(req, res){
    if(!areTemperatureRegisterParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        createNewTemperature(req, res)
    }
}

module.exports = {
    temperatureRegisterController
}
