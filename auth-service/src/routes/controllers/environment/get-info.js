const Environment = require('../../../mongoose/environment')

async function infoEnvironmentController(req, res){
    Environment.findById(req.query.id)
        .select("-_id -__v -password")
        .then(async environment => {
        if(environment !== null){
            res.status(200).json(environment)
        } else {
            res.status(404).json({err: "not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    infoEnvironmentController
}
