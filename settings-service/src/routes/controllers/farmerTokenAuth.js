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

const jwt = require('jsonwebtoken')
const farmerTokenSecret = require('../../conf').farmerTokenSecret

const verifyToken = (req, res, next) => {
    try {
        const decoded = jwt.verify(req.headers.token, farmerTokenSecret)
        req.farmerId = decoded.farmerId
        req.organizationId = decoded.organizationId
        next()
    }
    catch(ex){
        res.sendStatus(401)
    }
}

module.exports = {
    verifyToken
}
