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

import { useDispatch, useSelector } from 'react-redux'
import { useState } from 'react'

import environmentList from '../../../js/environment/environmentList'
import { setSelectedGreenhouse } from '../../../redux/greenhouses/actions'
import EnvironmentListModal from './EnvironmentListModal'
import List from '../../_common/List'

export default function GreenhousesList() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)
    let greenhouses = useSelector(state => state.greenhouses.list)
    const [showEnvironmentModal, setShowEnvironmentModal] = useState(false)

    return (
        <>
            <List
                elements = { greenhouses }
                keyGenerator = { (g) => { return g.name } }
                textGenerator = { (g) =>  { return g.name } }
                onElementClick = {(id) => {
                    dispatch(setSelectedGreenhouse(id))
                    environmentList(token, id, dispatch)
                    setShowEnvironmentModal(true)
                }}
            />
            <EnvironmentListModal show = { showEnvironmentModal } onHide = { () => setShowEnvironmentModal(false) } />
        </>
    )
}
