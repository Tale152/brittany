import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import { setSettingsList } from '../../redux/settings/actions'
import { settingsService } from '../../conf'

export default function settingsList(token, settingsId, dispatch){
    dispatch(setIsLoading(true))
    $.ajax({
        url: settingsService + "/settings/list?id=" + settingsId,
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
