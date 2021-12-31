import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import { setSelectedEnvironment, setEnvironmentList } from '../../../redux/environments/actions'
import greenhouseList from '../../../js/greenhouseList'
import environmentList from '../../../js/environmentList'
import List from '../../_common/List'
import CustomModal from '../../_common/CustomModal'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    const [showEnvironmentModal, setShowEnvironmentModal] = useState(false)
    let token = useSelector(state => state.identity.token)
    let greenhouses = useSelector(state => state.greenhouses.list)
    let environments = useSelector(state => state.environments.list)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <h1 className="d-flex justify-content-center">Greenhouses</h1>
            <List
                elements={greenhouses}
                onElementClick={(id) => {
                    dispatch(setSelectedGreenhouse(id))
                    environmentList(token, id, dispatch)
                    setShowEnvironmentModal(true)
                }}
            />
            <CustomModal
                show={showEnvironmentModal}
                onHide={() => {
                    dispatch(setSelectedGreenhouse(null))
                    dispatch(setEnvironmentList([]))
                    setShowEnvironmentModal(false)
                }}
                title={"Environments"}
                body={
                    <List
                        elements={environments}
                        onElementClick={(id) => {
                            dispatch(setSelectedEnvironment(id))
                        }}
                    />
                }
            />
        </div>   
    )
  
}
