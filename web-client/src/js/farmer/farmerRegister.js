import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import farmerList from './farmerList'
import { authService } from '../../conf'
import { isNonEmptyString } from '../util/validator'

export default function farmerRegister(token, name, surname, mail, birthdate, password, passwordConfirm, dispatch, alert){
    if(!validParams(name, surname, mail, birthdate, password, passwordConfirm)){
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
        $.post(authService + "/farmer/register", createParams(name, surname, mail, birthdate, password))
            .done(function () {
                farmerList(token, dispatch)
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


function validParams(name, surname, mail, birthdate, password, passwordConfirm){
    return isNonEmptyString(name) &&
        isNonEmptyString(surname) &&
        isNonEmptyString(mail) &&
        birthdate !== null &&
        isNonEmptyString(password) &&
        isNonEmptyString(passwordConfirm)
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
