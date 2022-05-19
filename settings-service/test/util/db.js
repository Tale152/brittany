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

const mongoose = require("mongoose")
const conf = require('../../src/conf')

module.exports.createConnectionToTestDB = function(completionCallback){
    mongoose.connect(
        conf.testDbAddress,
        { useNewUrlParser: true, useUnifiedTopology: true },
        () => completionCallback()
    )
}

module.exports.resetTestDB = async function(){
    const collections = await mongoose.connection.db.collections()

    for (let collection of collections) {
        await collection.drop()
    }
}

module.exports.dropConnectedTestDB = function(completionCallback){
    mongoose.connection.db.dropDatabase(() => {
      mongoose.connection.close(() => completionCallback())
    })
}
