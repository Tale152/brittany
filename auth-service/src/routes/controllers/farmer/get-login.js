const Farmer = require('../../../mongoose/farmer')

async function farmerLoginController(req, res){
    res.status(200).json({
        name: "test"
    })
}

module.exports = {
    farmerLoginController
}
