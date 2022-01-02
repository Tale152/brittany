import { useState } from 'react'

import OrganizationName from './OrganizationName'
import RedirectButton from './navigation/RedirectButton'

export default function Navbar(props){

    const [goToRedirect, setGoToRedirect] = useState(false)

    return (
        <>
            <OrganizationName />
            <RedirectButton
                text = { props.redirectText }
                destination = { props.redirectDestination }
                redirect = { goToRedirect }
                onClick = { () => setGoToRedirect(true) }
            />
            <hr />
        </>   
    )
}