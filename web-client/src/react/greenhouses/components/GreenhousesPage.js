import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouse/greenhouseList'
import CreateGreenhouseButton from './CreateGreenhouseButton'
import GreenhousesList from './GreenhousesList'
import EnvironmentListModal from './EnvironmentListModal'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    const [showEnvironmentModal, setShowEnvironmentModal] = useState(false)
    let token = useSelector(state => state.identity.token)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <h1 className="d-flex justify-content-center">Greenhouses</h1>
            <CreateGreenhouseButton />
            <GreenhousesList showEnvironmentModal = { () => setShowEnvironmentModal(true) } />
            <EnvironmentListModal show = { showEnvironmentModal } onHide = { () => setShowEnvironmentModal(false) } />
        </div>   
    )
  
}
