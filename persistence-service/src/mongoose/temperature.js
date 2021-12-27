const mongoose = require("mongoose")
const Schema = mongoose.Schema

let TemperatureSchema = new Schema({
    id_environment: {
        type: Schema.Types.ObjectId,
        require: true
    },
    timestamp: {
        type: Date,
        require: true,
    },
    value: {
        type: Number,
        require: true,
    },
})

module.exports = mongoose.model("Temperature", TemperatureSchema)
