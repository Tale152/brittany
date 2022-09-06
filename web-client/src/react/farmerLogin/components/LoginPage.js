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
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import RedirectButton from '../../_common/navigation/RedirectButton'

import farmerLogin from '../../../js/farmer/farmerLogin'

export default function LoginPage() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [inputMail, setInputMail] = useState(undefined)
    const [inputPassword, setInputPassword] = useState(undefined)

    function tryLogin(){
        farmerLogin(inputMail, inputPassword, dispatch, alert)
    }

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Row className="d-flex justify-content-center">
                <div style={{backgroundColor:"#66c95b"}} className="my-5 container col-lg-4 col-9 border border-success rounded trnsp">
                    <BrittanyTitle />
                    <Form className="mt-1 mb-3"  >
                        <h1 className="d-flex justify-content-center">Login</h1>
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter Mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { tryLogin }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Enter Password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { tryLogin }
                        />
                        <div className="mt-lg-3">
                            <CustomCenteredButton text={ "Login" } onClick = { tryLogin } />
                            <RedirectButton text = { "Register" } destination = { "register" } />
                        </div>
                    </Form>
                </div>
            </Row>
        </div>   
    )
  
}
