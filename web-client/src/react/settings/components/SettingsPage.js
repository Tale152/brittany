import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

export default function SettingsPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            TODO settings
        </div>   
    )
  
}
