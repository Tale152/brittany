import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import greenhouseList from './greenhouseList'

export default function greenhouseCreate(token, name, dispatch){
    dispatch(setIsLoading(true))
    $.ajaxSetup({
        contentType: "application/json; charset=utf-8",
        headers:{
           'token': token
        }
    })
    $.post("http://localhost:81/greenhouse/create", createParams(name))
        .done(function (result) {
            greenhouseList(token, dispatch)
        })
        .fail(function (result) {
            console.log("fail")
            dispatch(setIsLoading(false))
        })
}

function createParams(name) {
    return JSON.stringify({
        name: name
    })
}
