import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import farmerList from '../../../js/farmer/farmerList'
import Navbar from '../../_common/Navbar'
import FarmersList from './FarmersList'
import CreateFarmerButton from './CreateFarmerButton'

export default function FarmersPage(){

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    useEffect(() => farmerList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Greenhouses" }
                redirectDestination = { "greenhouses" }
            />
            <h2 className="d-flex justify-content-center">Farmers</h2>
            <CreateFarmerButton />
            <FarmersList />
        </div>   
    )
}
