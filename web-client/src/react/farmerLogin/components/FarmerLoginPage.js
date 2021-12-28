import { useState } from 'react'
import { useDispatch } from 'react-redux'
import Row from 'react-bootstrap/Row'
import Form from 'react-bootstrap/Form'

import FormText from '../../_common/form/input/FormText'
import FormPassword from '../../_common/form/input/FormPassword'
import FormLogin from '../../_common/form/button/FormLogin'
import RedirectButton from '../../_common/navigation/RedirectButton'

import farmerLogin from '../../../js/farmerLogin'

export default function FarmerLoginPage() {

    const dispatch = useDispatch()
    const [inputMail, setInputMail] = useState(undefined)
    const [inputPassword, setInputPassword] = useState(undefined)

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Row className="d-flex justify-content-center">
                <div className="my-5 container col-lg-3 col-9 border border-primary rounded trnsp">
                    <Form className="mt-1 mb-3"  >
                        <h1 className="d-flex justify-content-center">Farmer login</h1>
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter Mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { () => farmerLogin(inputMail, inputPassword, dispatch) }
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Enter Password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { () => farmerLogin(inputMail, inputPassword, dispatch) }
                        />
                        <div className="mt-lg-3">
                            <FormLogin
                                text={ "Login" } 
                                onClick = { () => farmerLogin(inputMail, inputPassword, dispatch) }
                            />
                            <RedirectButton
                                text = { "Register Organization" }
                                redirect = { false } //TODO
                                destination = { "TODO" } //TODO
                                onClick = { () => {console.log("Organization registration")}}
                            />
                        </div>
                    </Form>
                </div>
            </Row>
        </div>   
    )
  
}
