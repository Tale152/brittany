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
