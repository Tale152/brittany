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

import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import settingsList from './settingsList'
import { settingsService } from '../../conf'

export default function settingsLatestActiveState(token, settingsId, environmentId, active, dispatch){
    dispatch(setIsLoading(true))
    $.ajaxSetup({
        contentType: "application/json; charset=utf-8",
        headers:{
           'token': token
        }
    })
    $.post(settingsService + "/settings/latestActiveState", createParams(environmentId, active))
        .done(function (result) {
            settingsList(token, environmentId, dispatch)
        })
        .fail(function (result) {
            console.log("fail")
            dispatch(setIsLoading(false))
        })
}

function createParams(environmentId, active) {
    return JSON.stringify({
        idEnvironment: environmentId,
        active: !active
    })
}
