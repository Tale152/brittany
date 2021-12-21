const ObjectId = require('mongoose').Types.ObjectId

const Temperature = require('../../../mongoose/temperature')

async function temperatureLatestController(req, res){
    Temperature.findOne({ id_settings: new ObjectId(req.query.id) })
        .sort({timestamp: 'desc'})
        .select("-_id -id_settings -__v")
        .then(async temperature => {
            if(temperature !== null){
                res.status(200).json(temperature)
            } else {
                res.status(404).json({err: "not found"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    temperatureLatestController
}
