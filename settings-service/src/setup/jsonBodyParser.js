const bodyParser = require('body-parser')

module.exports.setBodyParser = function(server) {
    //decode every request body to json format
    server.use(bodyParser.json())
}
