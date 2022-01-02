import { useDispatch } from 'react-redux'
import { useSelector } from 'react-redux'

import formatTime from '../../../js/util/timeHelper'
import { setSelectedSetting } from '../../../redux/settings/actions'
import CustomModal from '../../_common/CustomModal'

export default function SettingsDetails(props) {

    const dispatch = useDispatch()
    let settings = useSelector(state => state.settings)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                dispatch(setSelectedSetting(null))
                props.onHide()
            }}
            title={"Setting info"}
            body={createSettingsInfo(settings, props.isCurrent)}
        />
    )
}

function createSettingsInfo(settings, isCurrent){
    if(settings.selected !== null){
        let selected = settings.list.find(f => f._id === settings.selected)
        return (
            <div>
                <p>Created: {selected.created.replace(/[A-Za-z]+/g, ' ')}</p>
                <p>Expires: {selected.expires.replace(/[A-Za-z]+/g, ' ')}</p>
                {isCurrent ? <p>Is active: {selected.active.toString()}</p> : <></>}
                <hr/>
                {selected.data.temperature === undefined ? <></> : <p>Temperature: Min({selected.data.temperature.min}) - Max({selected.data.temperature.max})</p>}
                {selected.data.airHumidity === undefined ? <></> : <p>Air humidity: Min({selected.data.airHumidity.min}) - Max({selected.data.airHumidity.max})</p>}
                {selected.data.light === undefined ? <></> : <p>Light: From({formatTime(selected.data.light.fromH, selected.data.light.fromM)}) - To({formatTime(selected.data.light.toH, selected.data.light.toM)})</p>}
            </div>
        )
    } else {
        <p></p>
    }
}
