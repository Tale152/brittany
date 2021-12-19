const mongoose = require('mongoose')
const Schema = mongoose.Schema

let EnvironmentSchema = new Schema({
    id_greenhouse: {
        type: Schema.Types.ObjectId,
        require: true,
    },
    name: {
        type: String,
        require: true,
    },
    password: {
        type: String,
        require: true,
    },
})

module.exports = mongoose.model("Environment", EnvironmentSchema)
