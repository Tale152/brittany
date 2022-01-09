import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import environmentList from './environmentList'
import { authService } from '../../conf'

export default function greenhouseCreate(token, greenhouseId, name, password, passwordConfirm, dispatch){
    //TODO check password
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
            console.log("fail")
            dispatch(setIsLoading(false))
        })
}

function createParams(name, password, greenhouseId) {
    return JSON.stringify({
        name: name,
        password: password,
        greenhouseId: greenhouseId
    })
}
