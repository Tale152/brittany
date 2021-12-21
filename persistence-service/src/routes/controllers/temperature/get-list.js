const ObjectId = require('mongoose').Types.ObjectId

const Temperature = require('../../../mongoose/temperature')

async function temperatureListController(req, res){
    Temperature.find({ id_settings: new ObjectId(req.query.id) })
        .sort({timestamp: 'desc'})
        .select("-_id -id_settings -__v")
        .then(async temperatures => {
            if(temperatures !== null){
                res.status(200).json({
                    temperatures: temperatures
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
    temperatureListController
}
