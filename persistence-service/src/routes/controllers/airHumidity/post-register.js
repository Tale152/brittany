const stringUtil = require('../util/stringUtil')
const numberUtil = require('../util/numberUtil')
const AirHumidityFactory = require('../../../mongoose/factories/airHumidity')

function areAirHumidityRegisterParametersValid(params){
    return stringUtil.isValidString(params.id) &&
        stringUtil.isValidString(params.timestamp) &&
        numberUtil.isValidNumber(params.value)
}

async function createNewAirHumidity(req, res){
    var newAirHumidity = AirHumidityFactory.createAirHumidity(
        req.body.id,
        req.body.timestamp,
        req.body.value
    )
    saveNewAirHumidity(newAirHumidity, res)
}

async function saveNewAirHumidity(airHumidity, res){
    airHumidity.save().then(() => {
        res.status(201).json({id: airHumidity._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function airHumidityRegisterController(req, res){
    if(!areAirHumidityRegisterParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        createNewAirHumidity(req, res)
    }
}

module.exports = {
    airHumidityRegisterController
}
