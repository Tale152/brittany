module.exports.setRoutes = function(server) {
    server.use(require('../routes/temperature'))
    server.use(require('../routes/airHumidity'))
}
