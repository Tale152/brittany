const express = require('express')
const setup = require('./setup/index')

const server = express()
setup.setupServer(server)
module.exports = server
