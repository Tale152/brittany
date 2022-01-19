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
                <div style={{backgroundColor:"#66c95b"}} className="my-5 container col-lg-3 col-9 border border-success rounded trnsp">
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
