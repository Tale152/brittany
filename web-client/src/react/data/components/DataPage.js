import { useDispatch, useSelector } from 'react-redux'

import Navbar from '../../_common/Navbar'
import RedirectButton from '../../_common/navigation/RedirectButton'

export default function DataPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let environmentId = useSelector(state => state.environments.selected)

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Settings" }
                redirectDestination = { "settings" }
                additionalContent = {<RedirectButton text = { "Back to Greenhouses" } destination = { "greenhouses" } />}
            />
            
        </div>   
    )
  
}
