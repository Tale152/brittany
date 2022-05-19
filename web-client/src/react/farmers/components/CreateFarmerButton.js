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

import farmerRegister from '../../../js/farmer/farmerRegister'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormPassword from '../../_common/form/input/FormPassword'
import FormText from '../../_common/form/input/FormText'
import FormDatePicker from '../../_common/form/FormDatePicker'

export default function CreateFarmerButton() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [inputName, setInputName] = useState("")
    const [inputSurname, setInputSurname] = useState("")
    const [inputMail, setInputMail] = useState("")
    const [inputBirthdate, setInputBirthdate] = useState(null)
    const [inputPassword, setInputPassword] = useState("")
    const [inputPasswordConfirm, setInputPasswordConfirm] = useState("")
    let token = useSelector(state => state.identity.token)

    function tryCreateFarmer(){
        farmerRegister(token, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch, alert)
        setShowModal(false)
        setInputName("")
        setInputSurname("")
        setInputMail("")
        setInputBirthdate(null)
        setInputPassword("")
        setInputPasswordConfirm("")
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
                title={"New Farmer"}
                body={
                    <>
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter new Farmer's name" }
                            onChange = { input => setInputName(input) }
                            onEnter = { tryCreateFarmer }
                        />
                        <FormText
                            text = { "Surname:" }
                            placeholder = { "Enter new Farmer's surname" }
                            onChange = { input => setInputSurname(input) }
                            onEnter = { tryCreateFarmer }
                        />
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter new Farmer's mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { tryCreateFarmer }
                        />
                        <FormDatePicker
                            text = { "Birthdate:" }
                            selected = { inputBirthdate }
                            onChange = { input => setInputBirthdate(input) }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Enter new Farmer's password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { tryCreateFarmer }
                        />
                        <FormPassword
                            text = { "Confirm password:" }
                            placeholder = { "Enter again new Farmer's password" }
                            onChange = { input => setInputPasswordConfirm(input) }
                            onEnter = { tryCreateFarmer }
                        />
                        <CustomCenteredButton
                            onClick = { tryCreateFarmer }
                            text = { "Create" }
                        />
                    </>
                }
            />
        </>
    )
}
