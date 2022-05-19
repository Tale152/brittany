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

import { setToken } from '../../redux/identity/actions'
import { setIsLoading } from '../../redux/util/actions'
import organizationInfo from './organizationInfo'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'
import { convertDate } from '../util/dateConverter'

$.ajaxSetup({
    contentType: "application/json; charset=utf-8"
})

export default function organizationRegister(organizationName, name, surname, mail, birthdate, password, passwordConfirm, dispatch, alert){
    if(!validParams(organizationName, name, surname, mail, birthdate, password, passwordConfirm)){
        alert.error("Empty fields")
    } else if(password.trim() !== passwordConfirm.trim()){
        alert.error("Wrong password confirm")
    } else {
        dispatch(setIsLoading(true))
        $.post(authService + "/organization/create", createParams(organizationName, name, surname, mail, birthdate, password))
        .done(function (result) {
            dispatch(setToken(result.token))
            organizationInfo(result.token, dispatch)
        })
        .fail(function (result) {
            if(result.status === 406){
                alert.error(result.responseJSON.err)
            } else {
                alert.error("Error contacting server")
            }
        }).always(function() {
            dispatch(setIsLoading(false))
        })
    }
}

function validParams(organizationName, name, surname, mail, birthdate, password, passwordConfirm){
    return isNonEmptyString(organizationName) &&
        isNonEmptyString(name) &&
        isNonEmptyString(surname) &&
        isNonEmptyString(mail) &&
        birthdate !== null &&
        isNonEmptyString(password) &&
        isNonEmptyString(passwordConfirm)
}

function createParams(organizationName, name, surname, mail, birthdate, password) {
    return JSON.stringify({
        organizationName: organizationName.trim(),
        name: name.trim(),
        surname: surname.trim(),
        mail: mail.trim(),
        birthdate: convertDate(birthdate),
        password: password.trim()
    })
}
