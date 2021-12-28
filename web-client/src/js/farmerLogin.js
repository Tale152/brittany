import $ from 'jquery'

import { setToken } from '../redux/identity/actions'

export default function farmerLogin(mail, password, dispatch){
    $.get("http://localhost:81/farmer/login", createParams(mail, password))
        .done(function (result) {
            dispatch(setToken(result.token))
        })
        .fail(function (result) {
            console.log("fail")
            console.log(result)
        })
}

function createParams(mail, password) {
    return {
        mail: mail.trim(),
        password: password.trim()
    }
}
