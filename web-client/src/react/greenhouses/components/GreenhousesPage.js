import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouseList'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    const [greenhouses, setGreenhouses] = useState([])
    let token = useSelector(state => state.identity.token)

    useEffect(() => {
        greenhouseList(token, dispatch).then((res) => {
            if(Array.isArray(res)){
                setGreenhouses(res)
            }
        })
    }, [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <p>{greenhouses.length}</p>
        </div>   
    )
  
}
