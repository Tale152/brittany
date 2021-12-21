const mongoose = require("mongoose")
const Schema = mongoose.Schema

let TemperatureSchema = new Schema({
    id_settings: {
        type: Schema.Types.ObjectId,
        require: true
    },
    time: {
        type: Date,
        require: true,
    },
    value: {
        type: Number,
        require: true,
    },
})

module.exports = mongoose.model("Temperature", TemperatureSchema)
