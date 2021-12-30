import Row from 'react-bootstrap/Row'
import ListGroup from 'react-bootstrap/ListGroup'

export default function List(props){
    return (
        <Row className="d-flex justify-content-center">
            <ListGroup className="my-5 container col-lg-3 col-9">
                {createList(props.elements)}
            </ListGroup>
        </Row>
    )
}

function createList(elements) {
    return (
        <>
            {elements.map(element => (
                <ListGroup.Item key={element.name}>{element.name}</ListGroup.Item>
            ))}
        </>
    );
}
