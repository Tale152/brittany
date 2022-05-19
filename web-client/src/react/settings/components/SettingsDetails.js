/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { useDispatch } from 'react-redux'
import { useSelector } from 'react-redux'

import formatTime from '../../../js/util/timeHelper'
import { setSelectedSetting } from '../../../redux/settings/actions'
import CustomModal from '../../_common/CustomModal'
import SwitchCurrentActiveStateButton from './SwitchCurrentActiveStateButton'

export default function SettingsDetails(props) {

    const dispatch = useDispatch()
    let settings = useSelector(state => state.settings)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                dispatch(setSelectedSetting(null))
                props.onHide()
            }}
            title={"Setting info"}
            body={createSettingsInfo(settings, props.isCurrent, dispatch, setSelectedSetting, props.onHide)}
        />
    )
}

function createSettingsInfo(settings, isCurrent, dispatch, setSelectedSetting, onHide){
    if(settings.selected !== null){
        let selected = settings.list.find(f => f._id === settings.selected)
        return (
            <div>
                <p>Created: {selected.created.replace(/[A-Za-z]+/g, ' ')}</p>
                <p>Expires: {selected.expires.replace(/[A-Za-z]+/g, ' ')}</p>
                {isCurrent ? <p>Is active: {selected.active.toString()}</p> : <></>}
                <hr/>
                {(selected.data === undefined || selected.data.temperature === undefined) ? <></> : <p>Temperature: Min({selected.data.temperature.min}) - Max({selected.data.temperature.max})</p>}
                {(selected.data === undefined || selected.data.airHumidity === undefined) ? <></> : <p>Air humidity: Min({selected.data.airHumidity.min}) - Max({selected.data.airHumidity.max})</p>}
                {(selected.data === undefined || selected.data.light === undefined) ? <></> : <p>Light: From({formatTime(selected.data.light.fromH, selected.data.light.fromM)}) - To({formatTime(selected.data.light.toH, selected.data.light.toM)})</p>}
                <SwitchCurrentActiveStateButton 
                    show = { isCurrent }
                    active = { selected.active }
                    onClick = {() => {
                        dispatch(setSelectedSetting(null))
                        onHide()
                    }}
                />
            </div>
        )
    } else {
        <p></p>
    }
}
