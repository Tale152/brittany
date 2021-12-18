const jwt = require('jsonwebtoken')
const farmerTokenSecret = require('../../conf').farmerTokenSecret

const verifyToken = (req, res, next) => {
    try {
        const decoded = jwt.verify(req.headers.token, farmerTokenSecret)
        req.farmerId = decoded.farmerId
        req.organizationId = decoded.organizationId
        next()
    }
    catch(ex){
        res.sendStatus(401)
    }
}

module.exports = {
    verifyToken
}
