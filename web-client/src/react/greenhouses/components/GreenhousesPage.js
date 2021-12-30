import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import greenhouseList from '../../../js/greenhouseList'
import List from '../../_common/List'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let list = useSelector(state => state.greenhouses.list)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <List elements={list} />
        </div>   
    )
  
}
