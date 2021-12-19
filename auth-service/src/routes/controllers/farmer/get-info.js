const Farmer = require('../../../mongoose/farmer')

async function farmerInfoController(req, res){
    Farmer.findById(req.body.id).then(async result => {
        if(result !== null && result.id_organization.toString() === req.organizationId){
            res.status(200).json({
                name: result.name,
                surname: result.surname,
                birthdate: result.birthdate,
                mail: result.mail
            })
        } else {
            res.status(404).json({err: "not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    farmerInfoController
}
