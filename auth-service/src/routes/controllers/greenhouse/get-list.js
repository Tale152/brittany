const Organization = require('../../../mongoose/organization')

async function listGreenhouseController(req, res){
    Organization.findById(req.organizationId).then(async organization => {
        if(organization !== null){
            organization.greenhouses.forEach(g => delete g.environments)
            res.status(200).json(organization.greenhouses)
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
