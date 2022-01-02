import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import FarmersInfoModal from './FarmersInfoModal'
import List from '../../_common/List'

export default function FarmersList() {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers.list)
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <List
                elements={farmers}
                keyGenerator = { (f) => { return f.name + " " + f.surname + " " + f.birthdate } }
                textGenerator = { (f) =>  { return f.name + " " + f.surname } }
                onElementClick={(id) => {
                    dispatch(setSelectedFarmer(id))
                    setShowModal(true)
                }}
            />
            <FarmersInfoModal show = { showModal } onHide = { () => setShowModal(false) } />
        </>
    )
}
