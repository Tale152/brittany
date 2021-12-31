import $ from 'jquery'

import { setOrganizationName } from '../../redux/identity/actions'

export default function organizationInfo(token, dispatch){
    $.ajax({
        url: "http://localhost:81/organization/info",
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setOrganizationName(result.name))
    }).fail(function (result) {
        console.log(result)
        dispatch(setOrganizationName("Err"))
    })
}
