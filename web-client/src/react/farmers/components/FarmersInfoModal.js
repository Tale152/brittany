import { useDispatch } from 'react-redux'
import { useSelector } from 'react-redux'

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import CustomModal from '../../_common/CustomModal'

export default function FarmersInfoModal(props) {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                dispatch(setSelectedFarmer(null))
                props.onHide()
            }}
            title={"Farmer info"}
            body={createFarmerInfo(farmers)}
        />
    )
}

function createFarmerInfo(farmers){
    if(farmers.selected !== null){
        let selected = farmers.list.find(f => f._id === farmers.selected)
        return (
            <div>
                <p>Name: {selected.name}</p>
                <p>Surname: {selected.surname}</p>
                <p>Mail: {selected.mail}</p>
                <p>Birthdate: {selected.birthdate}</p>
            </div>
        )
    } else {
        <p></p>
    }
}
