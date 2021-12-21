var mongoose = require('mongoose')
const server = require('./src/server')
var conf = require('./src/conf')

mongoose
    .connect(conf.dbAddress, {useNewUrlParser: true, useUnifiedTopology: true})
    .then(async () => {
        server.listen(conf.serverPort, () => {
            console.log(conf.asciiArt)
        })
    })
    .catch(err => {
        console.log("Error connecting to DB " + conf.dbAddress)
        console.log("DB connection:\n", err.message)
    })
