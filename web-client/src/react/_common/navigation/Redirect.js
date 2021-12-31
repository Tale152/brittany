import { Navigate, Link } from 'react-router-dom'

export default function RedirectTo(props){
    return <Link to={"/"+props.destination}><Navigate to={"/"+props.destination} /></Link>
}
