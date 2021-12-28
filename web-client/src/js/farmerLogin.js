import $ from 'jquery'

import { setToken } from '../redux/identity/actions'
import { setIsLoading } from '../redux/util/actions'

export default function farmerLogin(mail, password, dispatch){
    dispatch(setIsLoading(true))
    $.get("http://localhost:81/farmer/login", createParams(mail, password))
        .done(function (result) {
            dispatch(setToken(result.token))
        })
        .fail(function (result) {
            console.log("fail")
        }).always(function() {
            dispatch(setIsLoading(false))
        })
}

function createParams(mail, password) {
    return {
        mail: mail.trim(),
        password: password.trim()
    }
}
