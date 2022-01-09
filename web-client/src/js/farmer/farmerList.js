import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import { setFarmersList } from '../../redux/farmers/actions'
import { authService } from '../../conf'

export default function farmerList(token, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: authService + "/farmer/list",
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setFarmersList(result.farmers))
    }).fail(function (result) {
        console.log(result)
        dispatch(setFarmersList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}
