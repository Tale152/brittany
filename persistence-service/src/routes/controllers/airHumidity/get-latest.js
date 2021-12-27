const ObjectId = require('mongoose').Types.ObjectId

const AirHumidity = require('../../../mongoose/airHumidity')

async function airHumidityLatestController(req, res){
    AirHumidity.findOne({ id_environment: new ObjectId(req.environmentId) })
        .sort({timestamp: 'desc'})
        .select("-_id -id_environment -__v")
        .then(async airHumidity => {
            if(airHumidity !== null){
                res.status(200).json(airHumidity)
            } else {
                res.status(404).json({err: "not found"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    airHumidityLatestController
}
