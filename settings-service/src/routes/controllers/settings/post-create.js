const stringUtil = require('../util/stringUtil')
const SettingsFactory = require('../../../mongoose/factories/settings')

function areSettingsCreateParametersValid(params){
    return stringUtil.isValidString(params.idEnvironment) &&
        stringUtil.isValidString(params.expires)
}

async function createNewSettings(req, res){
    var newSettings = SettingsFactory.createSettings(
        req.body.idEnvironment,
        new Date(),
        req.body.expires,
        true
    )
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
