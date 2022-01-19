import BrittanyTitle from './BrittanyTitle'
import RedirectButton from './navigation/RedirectButton'

export default function Navbar(props){

    return (
        <div style={{backgroundColor:"#66c95b"}} className="border border-success trnsp">
            <BrittanyTitle />
            {props.additionalContent === undefined ? <></> : props.additionalContent}
            <RedirectButton
                text = { props.redirectText }
                destination = { props.redirectDestination }
            />
        </div>   
    )
}