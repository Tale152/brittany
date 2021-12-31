import { useState } from 'react'

import OrganizationName from '../../_common/OrganizationName'
import RedirectButton from '../../_common/navigation/RedirectButton'

export default function FarmersPage(){

    const [goToGreenhouses, setGoToGreenhouses] = useState(false)

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
        </div>   
    )
}
