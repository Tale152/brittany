const ObjectId = require('mongoose').Types.ObjectId

const AirHumidity = require('../../../mongoose/airHumidity')

async function airHumidityListController(req, res){
    AirHumidity.find({ id_settings: new ObjectId(req.query.id) })
        .sort({timestamp: 'desc'})
        .select("-_id -id_settings -__v")
        .then(async airHumidities => {
            if(airHumidities !== null){
                res.status(200).json({
                    airHumidities: airHumidities
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
    airHumidityListController
}
