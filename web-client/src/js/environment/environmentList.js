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
import { setEnvironmentList } from '../../redux/environments/actions'
import { authService } from '../../conf'

export default function environmentList(token, greenhouseId, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: authService + "/environment/list?id=" + greenhouseId,
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setEnvironmentList(result.environments))
    }).fail(function (result) {
        console.log(result)
        dispatch(setEnvironmentList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}
