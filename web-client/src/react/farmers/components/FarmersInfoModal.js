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

import { useDispatch } from 'react-redux'
import { useSelector } from 'react-redux'

import { setSelectedFarmer } from '../../../redux/farmers/actions'
import CustomModal from '../../_common/CustomModal'

export default function FarmersInfoModal(props) {

    const dispatch = useDispatch()
    let farmers = useSelector(state => state.farmers)

    return (
        <CustomModal
            show={props.show}
            onHide={() => {
                dispatch(setSelectedFarmer(null))
                props.onHide()
            }}
            title={"Farmer info"}
            body={createFarmerInfo(farmers)}
        />
    )
}

function createFarmerInfo(farmers){
    if(farmers.selected !== null){
        let selected = farmers.list.find(f => f._id === farmers.selected)
        return (
            <div>
                <p>Name: {selected.name}</p>
                <p>Surname: {selected.surname}</p>
                <p>Mail: {selected.mail}</p>
                <p>Birthdate: {selected.birthdate.substring(0, 10)}</p>
            </div>
        )
    } else {
        <p></p>
    }
}
