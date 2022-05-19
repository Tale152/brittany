/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import { setSelectedEnvironment, setEnvironmentList } from '../../../redux/environments/actions'
import CustomModal from '../../_common/CustomModal'
import CreateEnvironmentButton from './CreateEnvironmentButton'
import List from '../../_common/List'
import RedirectTo from '../../_common/navigation/Redirect'

export default function EnvironmentListModal(props) {

    const dispatch = useDispatch()
    let environments = useSelector(state => state.environments.list)
    const [goToSettings, setGoToSettings] = useState(false)

    if(goToSettings){
        return <RedirectTo destination={ "settings" } />
    } else {
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
                            colLgSize = { 8 }
                            elements={environments}
                            keyGenerator = { (e) => { return e.name } }
                            textGenerator = { (e) =>  { return e.name } }
                            onElementClick={(id) => {
                                dispatch(setSelectedEnvironment(id))
                                setGoToSettings(true)
                            }}
                        />
                    </>
                }
            />
        )
    }
}
