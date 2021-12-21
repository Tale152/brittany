const stringUtil = require('../util/stringUtil')
const numberUtil = require('../util/numberUtil')
const SettingsFactory = require('../../../mongoose/factories/settings')

function isRangeFieldValid(field){
    if(field !== undefined){
        return numberUtil.isValidNumber(field.min) && numberUtil.isValidNumber(field.max) && field.min <= field.max
    }
    return true
}

function areSettingsCreateParametersValid(params){
    if(stringUtil.isValidString(params.idEnvironment) && stringUtil.isValidString(params.expires)){
        return isRangeFieldValid(params.temperature) && isRangeFieldValid(params.humidity)
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
    if(req.body.humidity !== undefined){
        newSettings.data.humidity = req.body.humidity
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
