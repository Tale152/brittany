import $ from 'jquery'

import { setTemperature, setAirHumidity } from '../../redux/persistence/actions'
import { persistenceService } from '../../conf'

export default function listData(token, idEnvironment, dispatch){
    $.ajax({
        url: persistenceService + "/temperature/list?id=" + idEnvironment,
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setTemperature(result.list))
        $.ajax({
            url: persistenceService + "/airHumidity/list?id=" + idEnvironment,
            type: 'GET',
            headers: {"token": token}
        }).done(function (result) {
            dispatch(setAirHumidity(result.list))
        }).fail(function (result) {
            console.log(result)
            dispatch(setTemperature([]))
            dispatch(setAirHumidity([]))
        })
    }).fail(function (result) {
        console.log(result)
        dispatch(setTemperature([]))
        dispatch(setAirHumidity([]))
    })
}
