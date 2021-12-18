const ObjectId = require('mongoose').Types.ObjectId

const Greenhouse = require('../../../mongoose/greenhouse')

async function listGreenhouseController(req, res){
    Greenhouse.find({ id_organization: new ObjectId(req.organizationId) })
    .select("-id_organization -__v")
    .then(async greenhouses => {
        if(greenhouses !== null){
            greenhouses.forEach(g => {
                delete g.id_organization
            })
            res.status(200).json(greenhouses)
        } else {
            res.status(404).json({err: "Organization not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    listGreenhouseController
}
