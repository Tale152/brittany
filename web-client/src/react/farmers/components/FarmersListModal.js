import { useSelector } from 'react-redux'

import CustomModal from '../../_common/CustomModal'

export default function FarmersListModal(props) {

    let farmers = useSelector(state => state.farmers)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                
                props.onHide()
            }}
            title={"Farmer info"}
            body={createFarmerInfo(farmers)}
        />
    )
}

function createFarmerInfo(farmers){
    let selected = farmers.list.find(f => f._id === farmers.selected)
    return (
        <div>
            <p>Name: {selected.name}</p>
            <p>Surname: {selected.surname}</p>
            <p>Mail: {selected.mail}</p>
            <p>Birthdate: {selected.birthdate}</p>
        </div>
    )
}
