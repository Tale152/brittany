import { useDispatch, useSelector } from 'react-redux'

import environmentList from '../../../js/environmentList'
import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import List from '../../_common/List'

export default function GreenhousesList(props) {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let greenhouses = useSelector(state => state.greenhouses.list)

    return (
        <List
            elements={greenhouses}
            onElementClick={(id) => {
                dispatch(setSelectedGreenhouse(id))
                environmentList(token, id, dispatch)
                props.showEnvironmentModal()
            }}
        />
    )
}
