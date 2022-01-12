import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouse/greenhouseList'
import Navbar from '../../_common/Navbar'
import CreateGreenhouseButton from './CreateGreenhouseButton'
import GreenhousesList from './GreenhousesList'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Farmers" }
                redirectDestination = { "farmers" }
            />
            <h2 className="d-flex justify-content-center">Greenhouses</h2>
            <CreateGreenhouseButton />
            <GreenhousesList />
        </div>   
    )
  
}
