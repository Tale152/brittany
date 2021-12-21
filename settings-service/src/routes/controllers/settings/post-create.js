const stringUtil = require('../util/stringUtil')
const SettingsFactory = require('../../../mongoose/factories/settings')

function isTemperatureValid(temperature){
    if(temperature !== undefined){
        return temperature.min !== undefined && !isNaN(temperature.min) &&
            temperature.max !== undefined && !isNaN(temperature.max) &&
            temperature.min <= temperature.max
    }
    return true
}

function areSettingsCreateParametersValid(params){
    if(stringUtil.isValidString(params.idEnvironment) && stringUtil.isValidString(params.expires)){
        return isTemperatureValid(params.temperature)
    }
    return false
}

async function createNewSettings(req, res){
    var newSettings = SettingsFactory.createSettings(
        req.body.idEnvironment,
        new Date(),
        req.body.expires,
        true
    )
    if(req.body.temperature !== undefined){
        newSettings.data.temperature = req.body.temperature
    }
    saveNewSettings(newSettings, res)
}

async function saveNewSettings(settings, res){
    settings.save().then(() => {
        res.status(201).json({id: settings._id.toString()})
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function createSettingsController(req, res){
    if(!areSettingsCreateParametersValid(req.body)){
        res.status(406).json({err: "Invalid parameters"})
    } else {
        createNewSettings(req, res)
    }
}

module.exports = {
    createSettingsController
}
