const mongoose = require('mongoose')
const Schema = mongoose.Schema

let GreenhouseSchema = new Schema({
    name: {
        type: String,
        require: true,
    },
    environments: ['Environment']
})

module.exports = mongoose.model("Greenhouse", GreenhouseSchema)
