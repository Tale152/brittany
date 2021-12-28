import { useState } from 'react'
import Row from 'react-bootstrap/Row'
import Form from 'react-bootstrap/Form'

import FormText from '../../_common/form/input/FormText'
import FormPassword from '../../_common/form/input/FormPassword'
import FormLogin from '../../_common/form/button/FormLogin'

export default function FarmerLoginPage() {

    const [inputMail, setInputMail] = useState(undefined)
    const [inputPassword, setInputPassword] = useState(undefined)

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Row className="d-flex justify-content-center">
                <div className="my-5 container col-lg-3 col-9 border border-primary rounded trnsp">
                    <Form className="mt-1 mb-3"  >
                        <h1>Farmer login</h1>
                        <FormText
                            isLoading = { false }   //TODO
                            text = { "Mail:" }
                            placeholder = { "Enter Mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { () => {console.log("enter")} } //TODO
                        />
                        <FormPassword
                            isLoading = { false }   //TODO
                            text = { "Password:" }
                            placeholder = { "Enter Password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { () => {console.log("enter")} } //TODO
                        />
                        <div className="mt-lg-3">
                            <FormLogin
                                isLoading = { false }
                                text={ "Login" } 
                                onClick = { () => {console.log(inputMail + " " + inputPassword)} }
                            />
                        </div>
                    </Form>
                </div>
            </Row>
        </div>   
    )
  
}
