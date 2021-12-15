const jwt = require('jsonwebtoken')
const tokenSecret = require('../../conf').tokenSecret

const verifyToken = (req, res, next) => {
    try {
        const decoded = jwt.verify(req.headers.token, tokenSecret)
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
