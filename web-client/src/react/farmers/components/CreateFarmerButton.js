import { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'

import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormPassword from '../../_common/form/input/FormPassword'
import FormText from '../../_common/form/input/FormText'

export default function CreateFarmerButton() {

    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [inputName, setInputName] = useState("")
    const [inputSurname, setInputSurname] = useState("")
    const [inputMail, setInputMail] = useState("")
    const [inputBirthdate, setInputBirthdate] = useState("")
    const [inputPassword, setInputPassword] = useState("")
    const [inputPasswordConfirm, setInputPasswordConfirm] = useState("")
    let token = useSelector(state => state.identity.token)

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
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <FormText
                            text = { "Surname:" }
                            placeholder = { "Enter new Farmer's surname" }
                            onChange = { input => setInputSurname(input) }
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <FormText
                            text = { "Mail:" }
                            placeholder = { "Enter new Farmer's mail" }
                            onChange = { input => setInputMail(input) }
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <FormText
                            text = { "Birthdate:" }
                            placeholder = { "Enter new Farmer's birthdate" }
                            onChange = { input => setInputBirthdate(input) }
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <FormPassword
                            text = { "Password:" }
                            placeholder = { "Enter new Farmer's password" }
                            onChange = { input => setInputPassword(input) }
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <FormPassword
                            text = { "Confirm password:" }
                            placeholder = { "Enter again new Farmer's password" }
                            onChange = { input => setInputPasswordConfirm(input) }
                            onEnter = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                        />
                        <CustomCenteredButton
                            onClick = { () => {
                                //TODO
                                setShowModal(false)
                            }}
                            text = { "Create" }
                        />
                    </>
                }
            />
        </>
    )
}
