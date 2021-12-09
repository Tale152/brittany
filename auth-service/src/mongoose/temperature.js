const mongoose = require("mongoose")
const Schema = mongoose.Schema

let TemperatureSchema = new Schema({
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
