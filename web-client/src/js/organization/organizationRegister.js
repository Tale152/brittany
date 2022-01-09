import $ from 'jquery'

import { setToken } from '../../redux/identity/actions'
import { setIsLoading } from '../../redux/util/actions'
import organizationInfo from './organizationInfo'
import { authService } from '../../conf'

$.ajaxSetup({
    contentType: "application/json; charset=utf-8"
})

export default function organizationRegister(organizationName, name, surname, mail, birthdate, password, passwordConfirm, dispatch){
    dispatch(setIsLoading(true))
    $.post(authService + "/organization/create", createParams(organizationName, name, surname, mail, birthdate, password))
        .done(function (result) {
            dispatch(setToken(result.token))
            organizationInfo(result.token, dispatch)
        })
        .fail(function (result) {
            console.log("fail")
        }).always(function() {
            dispatch(setIsLoading(false))
        })
}

function createParams(organizationName, name, surname, mail, birthdate, password) {
    return JSON.stringify({
        organizationName: organizationName.trim(),
        name: name.trim(),
        surname: surname.trim(),
        mail: mail.trim(),
        birthdate: birthdate.trim(),
        password: password.trim()
    })
}
