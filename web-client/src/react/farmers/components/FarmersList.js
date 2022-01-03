import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import FarmersListModal from './FarmersListModal'
import List from '../../_common/List'

export default function FarmersList() {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers.list)
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <List
                elements={farmers}
                onElementClick={(id) => {
                    dispatch(setSelectedFarmer(id))
                    setShowModal(true)
                }}
            />
            <FarmersListModal show = { showModal } onHide = { () => setShowModal(false) } />
        </>
    )
}
