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

import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import farmerList from '../../../js/farmer/farmerList'
import Navbar from '../../_common/Navbar'
import FarmersList from './FarmersList'
import CreateFarmerButton from './CreateFarmerButton'

export default function FarmersPage(){

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    useEffect(() => farmerList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Greenhouses" }
                redirectDestination = { "greenhouses" }
            />
            <h2 className="d-flex justify-content-center">Farmers</h2>
            <CreateFarmerButton />
            <FarmersList />
        </div>   
    )
}
