const mongoose = require("mongoose")
const Schema = mongoose.Schema

let RoleSchema = new Schema({
    name: {
        type: String,
        require: true,
    }
})

module.exports = mongoose.model("Role", RoleSchema)
