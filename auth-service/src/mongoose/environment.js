const mongoose = require('mongoose')
const Schema = mongoose.Schema

let EnvironmentSchema = new Schema({
    name: {
        type: String,
        require: true,
    }
})

module.exports = mongoose.model("Environment", EnvironmentSchema)
