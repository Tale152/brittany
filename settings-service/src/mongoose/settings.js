const mongoose = require('mongoose')
const Schema = mongoose.Schema

let SettingsSchema = new Schema({
    id_environment: {
        type: Schema.Types.ObjectId,
        require: true
    },
    created: {
        type: Date,
        require: true
    },
    expires: {
        type: Date,
        require: true
    }
})

module.exports = mongoose.model("Settings", SettingsSchema)
