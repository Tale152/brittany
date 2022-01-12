import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import environmentList from '../../../js/environment/environmentList'
import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import EnvironmentListModal from './EnvironmentListModal'
import List from '../../_common/List'

export default function GreenhousesList() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let greenhouses = useSelector(state => state.greenhouses.list)
    const [showEnvironmentModal, setShowEnvironmentModal] = useState(false)

    return (
        <>
            <List
                elements = { greenhouses }
                keyGenerator = { (g) => { return g.name } }
                textGenerator = { (g) =>  { return g.name } }
                onElementClick = {(id) => {
                    dispatch(setSelectedGreenhouse(id))
                    environmentList(token, id, dispatch)
                    setShowEnvironmentModal(true)
                }}
            />
            <EnvironmentListModal show = { showEnvironmentModal } onHide = { () => setShowEnvironmentModal(false) } />
        </>
    )
}
