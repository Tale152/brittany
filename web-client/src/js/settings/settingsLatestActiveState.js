import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import settingsList from './settingsList'
import { settingsService } from '../../conf'

export default function settingsLatestActiveState(token, settingsId, environmentId, active, dispatch){
    dispatch(setIsLoading(true))
    $.ajaxSetup({
        contentType: "application/json; charset=utf-8",
        headers:{
           'token': token
        }
    })
    $.post(settingsService + "/settings/latestActiveState", createParams(environmentId, active))
        .done(function (result) {
            settingsList(token, environmentId, dispatch)
        })
        .fail(function (result) {
            console.log("fail")
            dispatch(setIsLoading(false))
        })
}

function createParams(environmentId, active) {
    return JSON.stringify({
        idEnvironment: environmentId,
        active: !active
    })
}
