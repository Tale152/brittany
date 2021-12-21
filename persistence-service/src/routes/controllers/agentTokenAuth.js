const jwt = require('jsonwebtoken')
const agentTokenSecret = require('../../conf').agentTokenSecret

const verifyToken = (req, res, next) => {
    try {
        const decoded = jwt.verify(req.headers.token, agentTokenSecret)
        req.environmentId = decoded.environmentId
        next()
    }
    catch(ex){
        res.sendStatus(401)
    }
}

module.exports = {
    verifyToken
}
