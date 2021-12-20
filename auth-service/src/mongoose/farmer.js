const mongoose = require('mongoose')
const Schema = mongoose.Schema
const bcrypt = require('bcryptjs')

const conf = require('../conf')

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

FarmerSchema.pre("save", function(next) {
    let farmer = this
    bcrypt.hash(farmer.password, conf.passwordSalt, function(err, hash) {
        if (err) {
            return next(err)
        }
        farmer.password = hash
        next()
    })
})

module.exports = mongoose.model("Farmer", FarmerSchema)
