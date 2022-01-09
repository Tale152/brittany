import $ from 'jquery'

import { setToken } from '../../redux/identity/actions'
import { setIsLoading } from '../../redux/util/actions'
import organizationInfo from '../organization/organizationInfo'
import { authService } from '../../conf'

export default function farmerLogin(mail, password, dispatch){
    dispatch(setIsLoading(true))
    $.get(authService + "/farmer/login", createParams(mail, password))
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

function createParams(mail, password) {
    return {
        mail: mail.trim(),
        password: password.trim()
    }
}
