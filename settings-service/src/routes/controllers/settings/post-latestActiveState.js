const ObjectId = require('mongoose').Types.ObjectId

const Settings = require('../../../mongoose/settings')

async function latestActiveStateSettingsController(req, res){
    Settings.findOne({ id_environment: new ObjectId(req.body.idEnvironment) })
        .sort({created: 'desc'})
        .select("-id_environment -__v")
        .then(async settings => {
            if(settings !== null){
                settings.active = req.body.active
                settings.save().then(() => {
                    res.status(201).json(settings)
                }).catch(err => {
                    res.status(500).json({err: err.toString()})
                })
            } else {
                res.status(404).json({err: "there are no settings for this Environment"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    latestActiveStateSettingsController
}
