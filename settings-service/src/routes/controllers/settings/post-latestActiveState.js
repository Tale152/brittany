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
const boolUtil = require('../util/boolUtil')
const Settings = require('../../../mongoose/settings')

async function findLatest(req, res){
    Settings.findOne({ id_environment: new ObjectId(req.body.idEnvironment) })
        .sort({created: 'desc'})
        .select("-id_environment -__v")
        .then(async settings => {
            if(settings !== null){
                settings.active = req.body.active
                settings.save().then(() => {
                    res.status(201).json(settings)
                }).catch(err => {
                    res.status(500).json({err: err.toString()})
                })
            } else {
                res.status(404).json({err: "there are no settings for this Environment"})
            }
        }
    ).catch(err => {
        res.status(500).json({err: err.toString()})
    })
}

async function latestActiveStateSettingsController(req, res){
    if(stringUtil.isValidString(req.body.idEnvironment) && boolUtil.isValidBoolean(req.body.active)){
        await findLatest(req, res)
    } else {
        res.status(406).json({err: "Wrong params"})
    }
}

module.exports = {
    latestActiveStateSettingsController
}
