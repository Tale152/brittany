import $ from 'jquery'

import { setIsLoading } from '../redux/util/actions'
import { setGreenhouseList } from '../redux/greenhouses/actions'

export default function greenhouseList(token, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: "http://localhost:81/greenhouse/list",
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setGreenhouseList(result.greenhouses))
    }).fail(function (result) {
        console.log(result)
        dispatch(setGreenhouseList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}
