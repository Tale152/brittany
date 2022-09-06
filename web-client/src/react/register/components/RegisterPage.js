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
import { useDispatch } from 'react-redux'
import Row from 'react-bootstrap/Row'
import Form from 'react-bootstrap/Form'
import { useAlert } from 'react-alert'

import BrittanyTitle from '../../_common/BrittanyTitle'
import FormText from '../../_common/form/input/FormText'
import FormPassword from '../../_common/form/input/FormPassword'
import FormDatePicker from '../../_common/form/FormDatePicker'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import RedirectButton from '../../_common/navigation/RedirectButton'

import organizationRegister from '../../../js/organization/organizationRegister'

export default function RegisterPage() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [inputOrganizationName, setOrganizationName] = useState("")
    const [inputName, setInputName] = useState("")
    const [inputSurname, setInputSurname] = useState("")
    const [inputMail, setInputMail] = useState("")
    const [inputBirthdate, setInputBirthdate] = useState(null)
    const [inputPassword, setInputPassword] = useState("")
    const [inputPasswordConfirm, setInputPasswordConfirm] = useState("")

    function tryRegister(){
        organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch, alert)
    }

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Row className="d-flex justify-content-center">
                <div style={{backgroundColor:"#66c95b"}} className="my-5 container col-lg-4 col-9 border border-success rounded trnsp">
                    <BrittanyTitle />
                    <Form className="mt-1 mb-3"  >
                        <h1 className="d-flex justify-content-center">Register</h1>
                        <FormText
                            text = { "Organization's name:" }
                            placeholder = { "Enter Organization's name" }
                            onChange = { input => setOrganizationName(input) }
                            onEnter = { tryRegister }
                        />
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter your name" }
                            onChange = { input => setInputName(input) }
                            onEnter = { tryRegister }
                        />
                        <FormText
                            text = { "Surname:" }
                            placeholder = { "Enter your surname" }
                            onChange = { input => setInputSurname(input) }
                            onEnter = { tryRegister }
                        />
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter your mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { tryRegister }
                        />
                        <FormDatePicker
                            text = { "Birthdate:" }
                            selected = { inputBirthdate }
                            onChange = { input => setInputBirthdate(input) }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Create a password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { tryRegister }
                        />
                        <FormPassword
                            text = { "Confirm password:" }
                            placeholder = { "Confirm password" }
                            onChange = { input => setInputPasswordConfirm(input) }
                            onEnter = { tryRegister }
                        />
                        <div className="mt-lg-3">
                            <CustomCenteredButton text={ "Register" }  onClick = { tryRegister } />
                            <RedirectButton text = { "Login" } destination = { "" } />
                        </div>
                    </Form>
                </div>
            </Row>
        </div>   
    )
  
}
