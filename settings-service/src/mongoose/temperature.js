const mongoose = require('mongoose')
const Schema = mongoose.Schema

let TemperatureSchema = new Schema({
    id_settings: {
        type: Schema.Types.ObjectId,
        require: true
    },
    max: {
        type: Number,
        require: true
    },
    min: {
        type: Number,
        require: true
    }
})

module.exports = mongoose.model("Temperature", TemperatureSchema)
