const bodyParser = require('./jsonBodyParser')
const routes = require('./routes')

module.exports.setupServer = function(server){
  bodyParser.setBodyParser(server)
  routes.setRoutes(server)
}
