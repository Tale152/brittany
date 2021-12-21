const cors = require('cors')

const bodyParser = require('./jsonBodyParser')
const routes = require('./routes')

module.exports.setupServer = function(server){
    server.use(cors())
    bodyParser.setBodyParser(server)
    routes.setRoutes(server)
}
