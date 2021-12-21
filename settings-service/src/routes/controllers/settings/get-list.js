const ObjectId = require('mongoose').Types.ObjectId

const Settings = require('../../../mongoose/settings')

async function listSettingsController(req, res){
    Settings.find({ id_environment: new ObjectId(req.query.id) })
        .sort({created: 'desc'})
        .select("-id_environment -__v")
        .then(async result => {
            if(result !== null){
                res.status(200).json({
                    settings: result
                })
            } else {
                res.status(404).json({err: "not found"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    listSettingsController
}
