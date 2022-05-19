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

const Greenhouse = require('../../../mongoose/greenhouse')

async function listGreenhouseController(req, res){
    Greenhouse.find({ id_organization: new ObjectId(req.organizationId) })
    .select("-id_organization -__v")
    .then(async greenhouses => {
        if(greenhouses !== null){
            greenhouses.forEach(g => {
                delete g.id_organization
            })
            res.status(200).json({
                greenhouses: greenhouses
            })
        } else {
            res.status(404).json({err: "Organization not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    listGreenhouseController
}
