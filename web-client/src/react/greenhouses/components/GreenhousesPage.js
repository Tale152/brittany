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

import greenhouseList from '../../../js/greenhouse/greenhouseList'
import Navbar from '../../_common/Navbar'
import CreateGreenhouseButton from './CreateGreenhouseButton'
import GreenhousesList from './GreenhousesList'

export default function GreenhousesPage() {

    const dispatch = useDispatch()
    let token = useSelector(state => state.identity.token)

    useEffect(() => greenhouseList(token, dispatch), [token, dispatch])

    return (
        <div role="main" style={{ overflowX: "hidden" }}>
            <Navbar
                redirectText = { "Go to Farmers" }
                redirectDestination = { "farmers" }
            />
            <h2 className="d-flex justify-content-center">Greenhouses</h2>
            <CreateGreenhouseButton />
            <GreenhousesList />
        </div>   
    )
  
}
