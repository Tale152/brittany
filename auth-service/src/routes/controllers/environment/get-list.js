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

const ObjectId = require('mongoose').Types.ObjectId

const stringUtil = require('../util/stringUtil')
const Environment = require('../../../mongoose/environment')

async function listEnvironmentController(req, res){
    if(stringUtil.isValidString(req.query.id)){
        Environment.find({ id_greenhouse: new ObjectId(req.query.id) })
        .select("-id_greenhouse -password -__v")
        .then(async environments => {
            res.status(200).json({
                environments: environments
            })
        }).catch(err => {
            res.status(500).json({err: err.toString()})
        })
    } else {
        res.status(404).json({err: "Greenhouse not found"})
    }
}

module.exports = {
    listEnvironmentController
}
