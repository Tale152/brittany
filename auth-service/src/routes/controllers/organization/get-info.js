const Organization = require('../../../mongoose/organization')

async function organizationInfoController(req, res){
    Organization.findOne({ _id: req.organizationId }).then(async result => {
        if(result !== null){
            res.status(200).json({
                name: result.name
            })
        } else {
            res.setStatus(404)
        }
    }).catch(err => {
        res.status(500).json({err: err})
    })
}

module.exports = {
    organizationInfoController
}
