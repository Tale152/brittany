const ObjectId = require('mongoose').Types.ObjectId

const stringUtil = require('../util/stringUtil')
const Environment = require('../../../mongoose/environment')

async function listEnvironmentController(req, res){
    if(stringUtil.isValidString(req.query.id)){
        Environment.find({ id_greenhouse: new ObjectId(req.query.id) })
        .select("-id_greenhouse -password -__v")
        .then(async environments => {
            res.status(200).json({
                environments: environments
            })
        }).catch(err => {
            res.status(500).json({err: err.toString()})
        })
    } else {
        res.status(404).json({err: "Greenhouse not found"})
    }
}

module.exports = {
    listEnvironmentController
}
