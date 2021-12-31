import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import greenhouseList from '../../../js/greenhouseList'
import environmentList from '../../../js/environmentList'
import List from '../../_common/List'
import EnvironmentListModal from './EnvironmentListModal'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    const [showEnvironmentModal, setShowEnvironmentModal] = useState(false)
    let token = useSelector(state => state.identity.token)
    let greenhouses = useSelector(state => state.greenhouses.list)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <h1 className="d-flex justify-content-center">Greenhouses</h1>
            <List
                elements={greenhouses}
                onElementClick={(id) => {
                    dispatch(setSelectedGreenhouse(id))
                    environmentList(token, id, dispatch)
                    setShowEnvironmentModal(true)
                }}
            />
            <EnvironmentListModal show = { showEnvironmentModal } onHide = { () => setShowEnvironmentModal(false) } />
        </div>   
    )
  
}
