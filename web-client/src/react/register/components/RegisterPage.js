import { useState } from 'react'
import { useDispatch } from 'react-redux'
import Row from 'react-bootstrap/Row'
import Form from 'react-bootstrap/Form'

import FormText from '../../_common/form/input/FormText'
import FormPassword from '../../_common/form/input/FormPassword'
import FormLogin from '../../_common/form/button/FormLogin'
import RedirectButton from '../../_common/navigation/RedirectButton'

import organizationRegister from '../../../js/organizationRegister'

export default function RegisterPage() {

    const dispatch = useDispatch()
    const [goToFarmerLogin, setGoToFarmerLogin] = useState(false)
    const [inputOrganizationName, setOrganizationName] = useState("")
    const [inputName, setInputName] = useState("")
    const [inputSurname, setInputSurname] = useState("")
    const [inputMail, setInputMail] = useState("")
    const [inputBirthdate, setInputBirthdate] = useState("")
    const [inputPassword, setInputPassword] = useState("")
    const [inputPasswordConfirm, setInputPasswordConfirm] = useState("")

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Row className="d-flex justify-content-center">
                <div className="my-5 container col-lg-3 col-9 border border-primary rounded trnsp">
                    <Form className="mt-1 mb-3"  >
                        <h1 className="d-flex justify-content-center">Register</h1>
                        <FormText
                            text = { "Organization's name:" }
                            placeholder = { "Enter Organization's name" }
                            onChange = { input => setOrganizationName(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter your name" }
                            onChange = { input => setInputName(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormText
                            text = { "Surname:" }
                            placeholder = { "Enter your surname" }
                            onChange = { input => setInputSurname(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter your mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormText
                            text = { "Birthdate:" }
                            placeholder = { "Enter your birthdate" }
                            onChange = { input => setInputBirthdate(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Create a password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <FormPassword
                            text = { "Confirm password:" }
                            placeholder = { "Confirm password" }
                            onChange = { input => setInputPasswordConfirm(input) }
                            onEnter = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                        />
                        <div className="mt-lg-3">
                            <FormLogin
                                text={ "Register" } 
                                onClick = { () => organizationRegister(inputOrganizationName, inputName, inputSurname, inputMail, inputBirthdate, inputPassword, inputPasswordConfirm, dispatch) }
                            />
                            <RedirectButton
                                text = { "Login" }
                                redirect = { goToFarmerLogin }
                                destination = { "" }
                                onClick = { () => setGoToFarmerLogin(true)}
                            />
                        </div>
                    </Form>
                </div>
            </Row>
        </div>   
    )
  
}
