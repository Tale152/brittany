import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import farmerList from '../../../js/farmer/farmerList'
import OrganizationName from '../../_common/OrganizationName'
import RedirectButton from '../../_common/navigation/RedirectButton'
import FarmersList from './FarmersList'
import CreateFarmerButton from './CreateFarmerButton'

export default function FarmersPage(){

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    const [goToGreenhouses, setGoToGreenhouses] = useState(false)

    useEffect(() => farmerList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <OrganizationName />
            <RedirectButton
                text = { "Go to Greenhouses" }
                destination = { "greenhouses" }
                redirect = { goToGreenhouses }
                onClick = { () => setGoToGreenhouses(true) }
            />
            <hr />
            <h2 className="d-flex justify-content-center">Farmers</h2>
            <CreateFarmerButton />
            <FarmersList />
        </div>   
    )
}
