import $ from 'jquery'

import { setOrganizationName } from '../../redux/identity/actions'
import { authService } from '../../conf'

export default function organizationInfo(token, dispatch){
    $.ajax({
        url: authService + "/organization/info",
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setOrganizationName(result.name))
    }).fail(function (result) {
        console.log(result)
        dispatch(setOrganizationName("Err"))
    })
}
