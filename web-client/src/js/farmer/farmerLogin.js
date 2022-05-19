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
import organizationInfo from '../organization/organizationInfo'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

export default function farmerLogin(mail, password, dispatch, alert){
    if(validParams(mail, password)){
        dispatch(setIsLoading(true))
        $.get(authService + "/farmer/login", createParams(mail, password))
            .done(function (result) {
                dispatch(setToken(result.token))
                organizationInfo(result.token, dispatch)
            })
            .fail(function (result) {
                if(result.status === 401){
                    alert.error("Invalid credentials")
                } else {
                    alert.error("Error contacting server")
                }
            }).always(function() {
                dispatch(setIsLoading(false))
            })
    } else {
        alert.error("Mail and/or password cannot be empty")
    }
}

function validParams(mail, password){
    return isNonEmptyString(mail) && isNonEmptyString(password)
}

function createParams(mail, password) {
    return {
        mail: mail.trim(),
        password: password.trim()
    }
}
