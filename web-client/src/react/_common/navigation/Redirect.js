import { Navigate, Link } from 'react-router-dom'

export default function RedirectTo(destination){
    return <Link to={"/"+destination}><Navigate to={"/"+destination} /></Link>
}
