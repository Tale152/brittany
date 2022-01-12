import { useSelector } from 'react-redux'

export default function OrganizationName(){
    return <h1 className="d-flex justify-content-center">{useSelector(state => state.identity.organizationName)}</h1>
}
