const mongoose = require('mongoose')
const Schema = mongoose.Schema

let LightSchema = new Schema({
    id_settings: {
        type: Schema.Types.ObjectId,
        require: true
    },
    fromH: {
        type: Number,
        require: true
    },
    fromM: {
        type: Number,
        require: true
    },
    toH: {
        type: Number,
        require: true
    },
    toM: {
        type: Number,
        require: true
    }
})

module.exports = mongoose.model("Light", LightSchema)
