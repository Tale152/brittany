import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import { setEnvironmentList } from '../../redux/environments/actions'
import { authService } from '../../conf'

export default function environmentList(token, greenhouseId, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: authService + "/environment/list?id=" + greenhouseId,
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setEnvironmentList(result.environments))
    }).fail(function (result) {
        console.log(result)
        dispatch(setEnvironmentList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}
