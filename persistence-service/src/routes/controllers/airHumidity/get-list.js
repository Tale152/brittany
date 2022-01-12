const ObjectId = require('mongoose').Types.ObjectId

const AirHumidity = require('../../../mongoose/airHumidity')

async function airHumidityListController(req, res){
    AirHumidity.find({ id_environment: new ObjectId(req.query.id) })
        .sort({timestamp: 'asc'})
        .select("-_id -id_environment -__v")
        .then(async airHumidities => {
            if(airHumidities !== null){
                res.status(200).json({
                    list: airHumidities
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
