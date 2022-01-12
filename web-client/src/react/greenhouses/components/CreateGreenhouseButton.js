import { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { useAlert } from 'react-alert'

import greenhouseCreate from '../../../js/greenhouse/greenhouseCreate'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormText from '../../_common/form/input/FormText'

export default function CreateGreenhouseButton() {

    const alert = useAlert()
    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [name, setName] = useState("")
    let token = useSelector(state => state.identity.token)

    function tryCreateGreenhouse(){
        greenhouseCreate(token, name, dispatch, alert)
        setShowModal(false)
        setName("")
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
                title={"New Greenhouse"}
                body={
                    <>
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter new Greenhouse's name" }
                            onChange = { input => setName(input) }
                            onEnter = { tryCreateGreenhouse }
                        />
                        <CustomCenteredButton
                            onClick = { tryCreateGreenhouse }
                            text = { "Create" }
                        />
                    </>
                }
            />
        </>
    )
}
