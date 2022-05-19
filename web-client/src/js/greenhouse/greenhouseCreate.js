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
import greenhouseList from './greenhouseList'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

export default function greenhouseCreate(token, name, dispatch, alert){
    if(validParams(name)){
        dispatch(setIsLoading(true))
        $.ajaxSetup({
            contentType: "application/json; charset=utf-8",
            headers:{
               'token': token
            }
        })
        $.post(authService + "/greenhouse/create", createParams(name))
            .done(function (result) {
                greenhouseList(token, dispatch)
            })
            .fail(function (result) {
                if(result.status === 406){
                    alert.error(result.responseJSON.err)
                } else {
                    alert.error("Error contacting server")
                }
                dispatch(setIsLoading(false))
            })
    } else {
        alert.error("Name cannot be empty")
    }
}

function validParams(name){
    return isNonEmptyString(name)
}

function createParams(name) {
    return JSON.stringify({
        name: name
    })
}
