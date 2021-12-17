const mongoose = require('mongoose')
const Schema = mongoose.Schema

let OrganizationSchema = new Schema({
    name: {
        type: String,
        require: true,
        unique: true
    },
    greenhouses: ['Greenhouse']
})

module.exports = mongoose.model("Organization", OrganizationSchema)
