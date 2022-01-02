import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import settingsList from '../../../js/settings/settingsList'

export default function SettingsPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let environmentId = useSelector(state => state.environments.selected)

    useEffect(() => settingsList(token, environmentId, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            TODO settings
        </div>   
    )
  
}
