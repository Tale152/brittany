const ObjectId = require('mongoose').Types.ObjectId

const Farmer = require('../../../mongoose/farmer')

async function farmerListController(req, res){
    Farmer.find({ id_organization: new ObjectId(req.organizationId) })
        .select("-password -id_organization -__v")
        .then(async result => {
            if(result !== null){
                res.status(200).json({
                    farmers: result
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
    farmerListController
}
