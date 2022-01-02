import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import { setSettingsList } from '../../redux/settings/actions'

export default function settingsList(token, settingsId, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: "http://localhost:82/settings/list?id=" + settingsId,
        type: 'GET',
        headers: {"token": token}
    }).done(function (result) {
        dispatch(setSettingsList(result.settings))
    }).fail(function (result) {
        console.log(result)
        dispatch(setSettingsList([]))
    }).always(function() {
        dispatch(setIsLoading(false))
    })
}
