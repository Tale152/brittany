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

import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import settingsList from '../../../js/settings/settingsList'
import Navbar from '../../_common/Navbar'
import RedirectButton from '../../_common/navigation/RedirectButton'
import CreateSettings from './CreateSettings'
import CurrentSetting from './CurrentSetting'
import SettingsList from './SettingsList'

export default function SettingsPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let environmentId = useSelector(state => state.environments.selected)

    useEffect(() => settingsList(token, environmentId, dispatch), [token, environmentId, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Data" }
                redirectDestination = { "data" }
                additionalContent = {<RedirectButton text = { "Back to Greenhouses" } destination = { "greenhouses" } />}
            />
            <h2 className="d-flex justify-content-center">Settings</h2>
            <CreateSettings />
            <CurrentSetting />
            <SettingsList />
        </div>   
    )
  
}
