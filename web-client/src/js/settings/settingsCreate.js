import $ from 'jquery'

import { setIsLoading } from '../../redux/util/actions'
import settingsList from './settingsList'
import { settingsService } from '../../conf'
import { convertDate } from '../util/dateConverter'

export default function settingsCreate(token, payload, environmentId, dispatch, alert){
    if(payload.expires !== null && payload.expires !== undefined){
        payload.expires = convertDate(payload.expires)
    }
    dispatch(setIsLoading(true))
    $.ajaxSetup({
        contentType: "application/json; charset=utf-8",
        headers:{
           'token': token
        }
    })
    $.post(settingsService + "/settings/create", createParams(payload))
        .done(function (result) {
            settingsList(token, environmentId, dispatch)
        })
        .fail(function (result) {
            if(result.status === 406){
                alert.error(result.responseJSON.err)
            } else {
                alert.error("Error contacting server")
            }
            dispatch(setIsLoading(false))
        })
}

function createParams(payload) {
    return JSON.stringify(payload)
}
