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

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import FarmersInfoModal from './FarmersInfoModal'
import List from '../../_common/List'

export default function FarmersList() {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers.list)
    const [showModal, setShowModal] = useState(false)

    return (
        <>
            <List
                elements={farmers}
                keyGenerator = { (f) => { return f.name + " " + f.surname + " " + f.birthdate } }
                textGenerator = { (f) =>  { return f.name + " " + f.surname } }
                onElementClick={(id) => {
                    dispatch(setSelectedFarmer(id))
                    setShowModal(true)
                }}
            />
            <FarmersInfoModal show = { showModal } onHide = { () => setShowModal(false) } />
        </>
    )
}
