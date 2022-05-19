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

import { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { useAlert } from 'react-alert'

import settingsCreate from '../../../js/settings/settingsCreate'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormDatePicker from '../../_common/form/FormDatePicker'
import FormText from '../../_common/form/input/FormText'

export default function CreateSettings() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [expire, setExpire] = useState(null)
    const [temperatureActive, setTemperatureActive] = useState(false)
    const [temperatureMin, setTemperatureMin] = useState(null)
    const [temperatureMax, setTemperatureMax] = useState(null)
    const [airHumidityActive, setAirHumidityActive] = useState(false)
    const [airHumidityMin, setAirHumidityMin] = useState(null)
    const [airHumidityMax, setAirHumidityMax] = useState(null)
    const [lightActive, setLightActive] = useState(false)
    const [lightFromH, setLightFromH] = useState(null)
    const [lightFromM, setLightFromM] = useState(null)
    const [lightToH, setLightToH] = useState(null)
    const [lightToM, setLightToM] = useState(null)
    let token = useSelector(state => state.identity.token)
    let idEnvironment = useSelector(state => state.environments.selected)

    function onHide(){
        setExpire(null)
        setTemperatureActive(false)
        setTemperatureMin(null)
        setTemperatureMax(null)
        setAirHumidityActive(false)
        setAirHumidityMin(null)
        setAirHumidityMax(null)
        setLightActive(false)
        setLightFromH(null)
        setLightFromM(null)
        setLightToH(null)
        setLightToM(null)
        setShowModal(false)
    }

    function createNew(){
        onHide()
        let payload = {
            idEnvironment: idEnvironment,
            expires: expire
        }
        if(temperatureActive){
            payload.temperature = {
                min: temperatureMin,
                max: temperatureMax
            }
        }
        if(airHumidityActive){
            payload.airHumidity = {
                min: airHumidityMin,
                max: airHumidityMax
            }
        }
        if(lightActive){
            payload.light = {
                fromH: lightFromH,
                fromM: lightFromM,
                toH: lightToH,
                toM: lightToM
            }
        }
        settingsCreate(token, payload, idEnvironment, dispatch, alert)
    }

    return (
        <>
            <CustomCenteredButton
                onClick = { () => setShowModal(true) }
                text = { "+ Create new" }
            />
            <CustomModal
                show = { showModal }
                onHide = { onHide }
                title = { "New Settings" }
                body = {
                    <>
                        <FormDatePicker
                            text = { "Expires:" }
                            selected = { expire }
                            onChange = { input => setExpire(input) }
                        />
                        {minMaxValue("Temperature", temperatureActive, () => setTemperatureActive(true), setTemperatureMin, setTemperatureMax, createNew)}
                        {minMaxValue("Air Humidity", airHumidityActive, () => setAirHumidityActive(true), setAirHumidityMin, setAirHumidityMax, createNew)}
                        {fromToValue("Light", lightActive, () => setLightActive(true), setLightFromH, setLightFromM, setLightToH, setLightToM, createNew)}
                        <CustomCenteredButton
                            onClick = { createNew }
                            text = { "Create" }
                        />
                    </>
                }
            />
        </>
    )
}

function minMaxValue(name, isActive, activate, onMinChange, onMaxChange, onEnter){
    if(isActive){
        return (
            <>
                <h2 className="d-flex justify-content-center">{name}</h2>
                <FormText
                    text = { "Min:" }
                    placeholder = { "Insert " + name + " min" }
                    onChange = { input => onMinChange(input) }
                    onEnter = { () => onEnter()}
                />
                <FormText
                    text = { "Max:" }
                    placeholder = { "Insert " + name + " max" }
                    onChange = { input => onMaxChange(input) }
                    onEnter = { () => onEnter()}
                />
            </>
        )
    } else {
        return (
            <CustomCenteredButton
                onClick = { () => activate()}
                text = { "Set " + name }
            />
        )
    }
}

function fromToValue(name, isActive, activate, onFromHChange, onFromMChange, onToHChange, onToMChange, onEnter){
    if(isActive){
        return (
            <>
                <h2 className="d-flex justify-content-center">{name}</h2>
                <FormText
                    text = { "From (h):" }
                    placeholder = { "Insert " + name + " starting hour" }
                    onChange = { input => onFromHChange(input) }
                    onEnter = { () => onEnter()}
                />
                <FormText
                    text = { "From (m):" }
                    placeholder = { "Insert " + name + " starting minutes" }
                    onChange = { input => onFromMChange(input) }
                    onEnter = { () => onEnter()}
                />
                <FormText
                    text = { "To (h):" }
                    placeholder = { "Insert " + name + " ending hour" }
                    onChange = { input => onToHChange(input) }
                    onEnter = { () => onEnter()}
                />
                <FormText
                    text = { "To (m):" }
                    placeholder = { "Insert " + name + " ending minutes" }
                    onChange = { input => onToMChange(input) }
                    onEnter = { () => onEnter()}
                />
            </>
        )
    } else {
        return (
            <CustomCenteredButton
                onClick = { () => activate()}
                text = { "Set " + name }
            />
        )
    }
}
