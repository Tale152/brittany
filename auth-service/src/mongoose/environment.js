const mongoose = require('mongoose')
const Schema = mongoose.Schema
const bcrypt = require('bcryptjs')

const conf = require('../conf')

let EnvironmentSchema = new Schema({
    id_greenhouse: {
        type: Schema.Types.ObjectId,
        require: true,
    },
    name: {
        type: String,
        require: true,
    },
    password: {
        type: String,
        require: true,
    },
})

EnvironmentSchema.pre("save", function(next) {
    let environment = this
    bcrypt.hash(environment.password, conf.passwordSalt, function(err, hash) {
        if (err) {
            return next(err)
        }
        environment.password = hash
        next()
    })
})

module.exports = mongoose.model("Environment", EnvironmentSchema)
