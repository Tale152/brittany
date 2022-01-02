import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import { setSelectedSetting } from '../../../redux/settings/actions'
import List from '../../_common/List'

export default function CurrentSetting() {

    const dispatch = useDispatch()
    let setting = useSelector(state => state.settings.list)
    if(setting.length > 0 && new Date(setting[0].expires) > new Date()){
        setting = [setting[0]]
    } else {
        setting = []
    }
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <h2 className="d-flex justify-content-center">Current</h2>
            <List
                elements={setting}
                keyGenerator = { (s) => { return s.created } }
                textGenerator = { (s) =>  { return "Created at: " + s.created.replace(/[A-Za-z]+/g, ' ') } }
                onElementClick={(id) => {
                    dispatch(setSelectedSetting(id))
                    setShowModal(true)
                }}
            />
        </>
    )
}
