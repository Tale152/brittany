import { useDispatch, useSelector } from 'react-redux'

import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import { setSelectedEnvironment, setEnvironmentList } from '../../../redux/environments/actions'
import CustomModal from '../../_common/CustomModal'
import CreateEnvironmentButton from './CreateEnvironmentButton'
import List from '../../_common/List'

export default function EnvironmentListModal(props) {

    const dispatch = useDispatch()
    let environments = useSelector(state => state.environments.list)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                dispatch(setSelectedGreenhouse(null))
                dispatch(setEnvironmentList([]))
                props.onHide()
            }}
            title={"Environments"}
            body={
                <>
                    <CreateEnvironmentButton />
                    <List
                        elements={environments}
                        onElementClick={(id) => {
                            dispatch(setSelectedEnvironment(id))
                        }}
                    />
                </>
            }
        />
    )
}
