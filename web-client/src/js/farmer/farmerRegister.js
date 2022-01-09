import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import farmerList from './farmerList'
import { authService } from '../../conf'

export default function farmerRegister(token, name, surname, mail, birthdate, password, passwordConfirm, dispatch){
    dispatch(setIsLoading(true))
    $.ajaxSetup({
        contentType: "application/json; charset=utf-8",
        headers:{
           'token': token
        }
    })
    //TODO check password
    $.post(authService + "/farmer/register", createParams(name, surname, mail, birthdate, password))
        .done(function (result) {
            farmerList(token, dispatch)
        })
        .fail(function (result) {
            console.log("fail")
            dispatch(setIsLoading(false))
        })
}

function createParams(name, surname, mail, birthdate, password) {
    return JSON.stringify({
        name: name,
        surname: surname,
        mail: mail,
        birthdate: birthdate,
        password: password
    })
}
