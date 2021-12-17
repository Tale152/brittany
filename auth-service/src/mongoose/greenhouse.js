const mongoose = require('mongoose')
const Schema = mongoose.Schema

let GreenhouseSchema = new Schema({
    name: {
        type: String,
        require: true,
    },
    environments: [{
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Environment'
    }]
})

module.exports = mongoose.model("Greenhouse", GreenhouseSchema)
