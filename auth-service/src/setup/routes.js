module.exports.setRoutes = function(server) {
    server.use(require('../routes/organization'))
    server.use(require('../routes/farmer'))
}
