const ObjectId = require('mongoose').Types.ObjectId

const Temperature = require('../../../mongoose/temperature')

async function temperatureListController(req, res){
    Temperature.find({ id_environment: new ObjectId(req.query.id) })
        .sort({timestamp: 'asc'})
        .select("-_id -id_environment -__v")
        .then(async temperatures => {
            if(temperatures !== null){
                res.status(200).json({
                    list: temperatures
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
