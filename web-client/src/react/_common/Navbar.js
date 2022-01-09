import OrganizationName from './OrganizationName'
import RedirectButton from './navigation/RedirectButton'

export default function Navbar(props){

    return (
        <>
            <OrganizationName />
            {props.additionalContent === undefined ? <></> : props.additionalContent}
            <RedirectButton
                text = { props.redirectText }
                destination = { props.redirectDestination }
            />
            <hr />
        </>   
    )
}