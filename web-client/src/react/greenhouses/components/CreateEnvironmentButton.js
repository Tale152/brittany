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

import environmentCreate from '../../../js/environment/environmentCreate'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormText from '../../_common/form/input/FormText'
import FormPassword from '../../_common/form/input/FormPassword'

export default function CreateEnvironmentButton() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [name, setName] = useState("")
    const [password, setPassword] = useState("")
    const [passwordConfirm, setPasswordConfirm] = useState("")
    let token = useSelector(state => state.identity.token)
    let greenhouseId = useSelector(state => state.greenhouses.selected)

    function tryCreateEnvironment(){
        environmentCreate(token, greenhouseId, name, password, passwordConfirm, dispatch, alert)
        setShowModal(false)
        setName("")
        setPassword("")
        setPasswordConfirm("")
    }

    return (
        <>
            <CustomCenteredButton
                onClick = { () => setShowModal(true) }
                text = { "+ Create new" }
            />
            <CustomModal
                show={showModal}
                onHide={() => setShowModal(false)}
                title={"New Environment"}
                body={
                    <>
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter new Greenhouse's name" }
                            onChange = { input => setName(input) }
                            onEnter = { tryCreateEnvironment }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Enter password" }
                            onChange = { input => setPassword(input) }
                            onEnter = { tryCreateEnvironment }
                        />
                        <FormPassword
                            text = { "Confirm password:" }
                            placeholder = { "Enter password again" }
                            onChange = { input => setPasswordConfirm(input) }
                            onEnter = { tryCreateEnvironment }
                        />
                        <CustomCenteredButton
                            onClick = { tryCreateEnvironment }
                            text = { "Create" }
                        />
                    </>
                }
            />
        </>
    )
}
