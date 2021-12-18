const mongoose = require('mongoose')
const Schema = mongoose.Schema

let GreenhouseSchema = new Schema({
    id_organization: {
        type: Schema.Types.ObjectId,
        require: true
    },
    name: {
        type: String,
        require: true,
    }
})

module.exports = mongoose.model("Greenhouse", GreenhouseSchema)
