import { useDispatch, useSelector } from 'react-redux'

import settingsLatestActiveState from '../../../js/settings/settingsLatestActiveState'
import CustomCenteredButton from '../../_common/CustomCenteredButton'

export default function SwitchCurrentActiveStateButton(props){

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let settingsId = useSelector(state => state.settings.selected)
    let environmentId = useSelector(state => state.environments.selected)

    if(props.show){
        return(
            <CustomCenteredButton
                onClick = { () => {
                    settingsLatestActiveState(token, settingsId, environmentId, props.active, dispatch)
                    props.onClick()
                }}
                text = { "Switch state" }
            />
        )
    } else {
        return <></>
    }
}
