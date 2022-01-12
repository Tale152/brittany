import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import environmentList from './environmentList'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

export default function greenhouseCreate(token, greenhouseId, name, password, passwordConfirm, dispatch, alert){
    if(!validParams(name, password, passwordConfirm)){
        alert.error("Empty fields")
    } else if(password.trim() !== passwordConfirm.trim()){
        alert.error("Wrong password confirm")
    } else {
        dispatch(setIsLoading(true))
        $.ajaxSetup({
            contentType: "application/json; charset=utf-8",
            headers:{
               'token': token
            }
        })
        $.post(authService + "/environment/create", createParams(name, password, greenhouseId))
            .done(function (result) {
                environmentList(token, greenhouseId, dispatch)
            })
            .fail(function (result) {
                if(result.status === 406){
                    alert.error(result.responseJSON.err)
                } else {
                    alert.error("Error contacting server")
                }
                dispatch(setIsLoading(false))
            })
    }
}

function validParams(name, password, passwordConfirm){
    return isNonEmptyString(name) &&
        isNonEmptyString(password) &&
        isNonEmptyString(passwordConfirm)
}

function createParams(name, password, greenhouseId) {
    return JSON.stringify({
        name: name,
        password: password,
        greenhouseId: greenhouseId
    })
}
