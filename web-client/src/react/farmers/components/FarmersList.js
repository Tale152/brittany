import { useDispatch, useSelector } from 'react-redux'

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import List from '../../_common/List'

export default function FarmersList() {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers.list)

    return (
        <>
            <List
                elements={farmers}
                onElementClick={(id) => {
                    dispatch(setSelectedFarmer(id))
                }}
            />
        </>
    )
}
