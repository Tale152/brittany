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
import { setSettingsList } from '../../redux/settings/actions'
import { settingsService } from '../../conf'

export default function settingsList(token, settingsId, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: settingsService + "/settings/list?id=" + settingsId,
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setSettingsList(result.settings))
    }).fail(function (result) {
        console.log(result)
        dispatch(setSettingsList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}