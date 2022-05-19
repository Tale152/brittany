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

import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import { setSelectedSetting } from '../../../redux/settings/actions'
import List from '../../_common/List'
import SettingsDetails from './SettingsDetails'

export default function CurrentSetting() {

    const dispatch = useDispatch()
    let setting = useSelector(state => state.settings.list)
    if(setting.length > 0 && new Date(setting[0].expires) > new Date()){
        setting = [setting[0]]
    } else {
        setting = []
    }
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <h2 className="d-flex justify-content-center">Current</h2>
            <List
                elements={setting}
                keyGenerator = { (s) => { return s.created } }
                textGenerator = { (s) =>  { return "Created at: " + s.created.replace(/[A-Za-z]+/g, ' ') } }
                onElementClick={(id) => {
                    dispatch(setSelectedSetting(id))
                    setShowModal(true)
                }}
            />
            <SettingsDetails
                show = { showModal }
                onHide = { () => {setShowModal(false)} }
                isCurrent = { true }
            />
        </>
    )
}
