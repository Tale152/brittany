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

const Farmer = require('../../../mongoose/farmer')

async function farmerInfoController(req, res){
    Farmer.findById(req.query.id).then(async result => {
        if(result !== null && result.id_organization.toString() === req.organizationId){
            res.status(200).json({
                name: result.name,
                surname: result.surname,
                birthdate: result.birthdate,
                mail: result.mail
            })
        } else {
            res.status(404).json({err: "not found"})
        }
    }).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

module.exports = {
    farmerInfoController
}
