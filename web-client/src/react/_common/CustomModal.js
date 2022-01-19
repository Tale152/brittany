import Modal from 'react-bootstrap/Modal'

export default function CustomModal(props){
    return (
        <Modal backdrop="static" centered show={props.show} onHide={props.onHide}>
            <Modal.Header closeButton style={{backgroundColor: "#d7f8d3"}}>
                <Modal.Title>{props.title}</Modal.Title>
            </Modal.Header>
            <Modal.Body style={{backgroundColor: "#d7f8d3"}}>
                {props.body}
            </Modal.Body>
        </Modal>
    )
}
