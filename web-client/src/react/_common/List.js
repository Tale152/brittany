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
import Spinner from 'react-bootstrap/Spinner'

import Row from 'react-bootstrap/Row'
import ListGroup from 'react-bootstrap/ListGroup'

export default function List(props){
    if(useSelector(state => state.util.isLoading)){
        return (
            <Row className="d-flex justify-content-center">
                <Spinner className="my-5 container col-lg-3 col-9" animation="grow" />
            </Row>
        )
    } else if(props.elements.length === 0){
        return (<p className="d-flex justify-content-center">No existing elements</p>)
    } else {
        let colLgSize = ( props.colLgSize === null || props.colLgSize === undefined ) ? 4 : props.colLgSize
        let listClassName = "my-5 container col-lg-" + colLgSize + " col-14"
        return (
            <Row className="d-flex justify-content-center">
                <ListGroup className={ listClassName }>
                    {createList(props.elements, props.keyGenerator, props.textGenerator, props.onElementClick)}
                </ListGroup>
            </Row>
        )
    }
}

function createList(elements, keyGenerator, textGenerator, onElementClick) {
    return (
        <>
            {elements.map(element => (
                <ListGroup.Item 
                    key={keyGenerator(element)} 
                    action 
                    onClick={() => onElementClick(element._id)}
                    className = "border-2 border-dark rounded my-1"
                    style={{backgroundColor: "#198754", color: "white", textAlign: "center"}}
                >
                    {textGenerator(element)}
                </ListGroup.Item>
            ))}
        </>
    )
}
