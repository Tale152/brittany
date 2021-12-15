const cors = require('cors')
var mongoose = require('mongoose')
const server = require('./src/server')
var conf = require('./src/conf')
const rolesSetup = require('./src/setup/populateRoles')

const whitelist = [conf.webClientAddress]
const corsOptions = {
    origin: function(origin, callback){
        if(whitelist.indexOf(origin) === -1){
            var message = "The CORS policy for this origin doesn't allow access from the particular origin."
            return callback(new Error(message), false)
        }
        return callback(null, true)
      },
    credentials: true,
  }
server.use(cors(corsOptions))

mongoose
    .connect(conf.dbAddress, {useNewUrlParser: true, useUnifiedTopology: true})
    .then(async () => {
        await rolesSetup.populateRoles()
        server.listen(conf.serverPort, () => {
            console.log(conf.asciiArt)
        })
    })
    .catch(err => {
        console.log("Error connecting to DB " + conf.dbAddress)
        console.log("DB connection:\n", err.message)
    })
