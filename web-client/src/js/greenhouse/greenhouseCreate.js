import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import greenhouseList from './greenhouseList'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

export default function greenhouseCreate(token, name, dispatch, alert){
    if(validParams(name)){
        dispatch(setIsLoading(true))
        $.ajaxSetup({
            contentType: "application/json; charset=utf-8",
            headers:{
               'token': token
            }
        })
        $.post(authService + "/greenhouse/create", createParams(name))
            .done(function (result) {
                greenhouseList(token, dispatch)
            })
            .fail(function (result) {
                if(result.status === 406){
                    alert.error(result.responseJSON.err)
                } else {
                    alert.error("Error contacting server")
                }
                dispatch(setIsLoading(false))
            })
    } else {
        alert.error("Name cannot be empty")
    }
}

function validParams(name){
    return isNonEmptyString(name)
}

function createParams(name) {
    return JSON.stringify({
        name: name
    })
}
