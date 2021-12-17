const mongoose = require('mongoose')
const Schema = mongoose.Schema

let FarmerSchema = new Schema({
    name: {
        type: String,
        require: true,
    },
    surname: {
        type: String,
        require: true,
    },
    birthdate: {
        type: Date,
        require: true
    },
    mail: {
        type: String,
        require: true,
        unique: true
    },
    password: {
        type: String,
        require: true
    },
    id_organization: {
        type: Schema.Types.ObjectId,
        require: true
    }
})

module.exports = mongoose.model("Farmer", FarmerSchema)
