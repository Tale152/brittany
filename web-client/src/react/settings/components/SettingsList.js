import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import { setSelectedSetting } from '../../../redux/settings/actions'
import List from '../../_common/List'
import SettingsDetails from './SettingsDetails'

export default function SettingsList() {

    const dispatch = useDispatch()
    let settings = useSelector(state => state.settings.list)
    let old
    if(settings.length > 0 && new Date(settings[0].expires) > new Date()){
        old = [...settings]
        old.shift()
    } else {
        old = settings
    }
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <h2 className="d-flex justify-content-center">Old</h2>
            <List
                elements={old}
                keyGenerator = { (s) => { return s.created } }
                textGenerator = { (s) =>  { return "Created at: " + s.created.replace(/[A-Za-z]+/g, ' ') } }
                onElementClick={(id) => {
                    dispatch(setSelectedSetting(id))
                    setShowModal(true)
                }}
            />
            <SettingsDetails
                show = { showModal }
                onHide = { () => {setShowModal(false)} }
                isCurrent = { false }
            />
        </>
    )
}
