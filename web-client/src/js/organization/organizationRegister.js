import $ from 'jquery'

import { setToken } from '../../redux/identity/actions'
import { setIsLoading } from '../../redux/util/actions'
import organizationInfo from './organizationInfo'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

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
        isNonEmptyString(birthdate) &&
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

function convertDate(date){
    return date.getFullYear() + "-" + correctValue(date.getMonth() + 1) + "-" + correctValue(date.getDate())
}

function correctValue(v){
    return parseInt(v > 9 ? v : ("0" + v))
}
