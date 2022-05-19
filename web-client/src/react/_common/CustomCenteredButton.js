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
import Row from 'react-bootstrap/Row'
import Button from 'react-bootstrap/Button'

export default function CustomCenteredButton(props){
    return (
        <Row className="d-flex justify-content-center">
            <Button
                style = { useSelector(state => state.util.isLoading) ? { pointerEvents: "none", opacity: "0.4", width: '18rem' } : { width: '18rem' } }
                className = "col-11 my-2 border-2 border-dark"
                border = "dark"
                variant = "success"
                onClick = {props.onClick}
            >
                {props.text}
            </Button>
        </Row>
    )
}
