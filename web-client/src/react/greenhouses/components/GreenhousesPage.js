import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouse/greenhouseList'
import OrganizationName from '../../_common/OrganizationName'
import CreateGreenhouseButton from './CreateGreenhouseButton'
import GreenhousesList from './GreenhousesList'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <OrganizationName />
            <h2 className="d-flex justify-content-center">Greenhouses</h2>
            <CreateGreenhouseButton />
            <GreenhousesList />
        </div>   
    )
  
}
