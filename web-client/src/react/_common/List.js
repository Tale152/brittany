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
                    className = "border-2 border-dark rounded"
                    style={{backgroundColor: "#198754", color: "white", textAlign: "center"}}
                >
                    {textGenerator(element)}
                </ListGroup.Item>
            ))}
        </>
    )
}
