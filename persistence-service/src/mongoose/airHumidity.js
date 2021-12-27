const mongoose = require("mongoose")
const Schema = mongoose.Schema

let AirHumiditySchema = new Schema({
    id_settings: {
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

module.exports = mongoose.model("Air_Humidity", AirHumiditySchema)
