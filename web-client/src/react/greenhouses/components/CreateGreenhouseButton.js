import { useState } from 'react'
import { useSelector, useDispatch } from 'react-redux'

import greenhouseCreate from '../../../js/greenhouse/greenhouseCreate'
import CustomCenteredButton from '../../_common/CustomCenteredButton'
import CustomModal from '../../_common/CustomModal'
import FormText from '../../_common/form/input/FormText'

export default function CreateGreenhouseButton() {

    const dispatch = useDispatch()
    const [showModal, setShowModal] = useState(false)
    const [name, setName] = useState("")
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
                title={"New Greenhouse"}
                body={
                    <>
                        <FormText
                            text = { "Name:" }
                            placeholder = { "Enter new Greenhouse's name" }
                            onChange = { input => setName(input) }
                            onEnter = { () => {
                                greenhouseCreate(token, name, dispatch)
                                setShowModal(false)
                            }}
                        />
                        <CustomCenteredButton
                            onClick = { () => {
                                greenhouseCreate(token, name, dispatch)
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
