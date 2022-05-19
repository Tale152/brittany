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

import { useSelector } from 'react-redux'
import Form from 'react-bootstrap/Form'

export default function FormInput(props){
    return (
        <>
            <h3>{props.text}</h3>
            <Form.Control
                style={useSelector(state => state.util.isLoading) ? { pointerEvents: "none", opacity: "0.4", backgroundColor: "#d7f8d3" } : { backgroundColor: "#d7f8d3" }}
                className = "border-2 border-dark"
                type={props.type}
                onChange={e => props.onChange(e.target.value)}
                placeholder={props.placeholder}
                onKeyPress={event => { if (event.charCode === 13) props.onEnter() }}
            />
        </>
    )
}
