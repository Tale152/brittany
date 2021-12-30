import $ from 'jquery'

import { setIsLoading } from '../redux/util/actions'

export default async function greenhouseList(token, dispatch){
    dispatch(setIsLoading(true))
    let greenhouses = "Something went wrong retreiving greenhouses"
    await $.ajax({
        url: "http://localhost:81/greenhouse/list",
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        greenhouses = result.greenhouses
    })
    .always(function() {
        dispatch(setIsLoading(false))
    })
    return greenhouses
}
