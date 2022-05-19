/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
