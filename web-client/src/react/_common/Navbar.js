import OrganizationName from './OrganizationName'
import RedirectButton from './navigation/RedirectButton'

export default function Navbar(props){

    return (
        <div style={{backgroundColor:"#d7f8d3"}} className="border border-success trnsp">
            <OrganizationName />
            {props.additionalContent === undefined ? <></> : props.additionalContent}
            <RedirectButton
                text = { props.redirectText }
                destination = { props.redirectDestination }
            />
        </div>   
    )
}