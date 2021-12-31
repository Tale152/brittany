import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouse/greenhouseList'
import OrganizationName from '../../_common/OrganizationName'
import RedirectButton from '../../_common/navigation/RedirectButton'
import CreateGreenhouseButton from './CreateGreenhouseButton'
import GreenhousesList from './GreenhousesList'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    const [goToFarmers, setGoToFarmers] = useState(false)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <OrganizationName />
            <RedirectButton
                text = { "Go to Farmers" }
                destination = { "farmers" }
                redirect = { goToFarmers }
                onClick = { () => setGoToFarmers(true) }
            />
            <hr />
            <h2 className="d-flex justify-content-center">Greenhouses</h2>
            <CreateGreenhouseButton />
            <GreenhousesList />
        </div>   
    )
  
}
