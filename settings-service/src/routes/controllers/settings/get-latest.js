const ObjectId = require('mongoose').Types.ObjectId

const Settings = require('../../../mongoose/settings')

async function latestSettingsController(req, res){
    Settings.findOne({ id_environment: new ObjectId(req.environmentId) })
        .sort({created: 'desc'})
        .select("-id_environment -__v")
        .then(async result => {
            if(result !== null){
                res.status(200).json(result)
            } else {
                res.status(404).json({err: "not found"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    latestSettingsController
}
