import Modal from 'react-bootstrap/Modal'

export default function CustomModal(props){
    return (
        <Modal show={props.show} onHide={props.onHide}>
            <Modal.Header closeButton>
                <Modal.Title>{props.title}</Modal.Title>
            </Modal.Header>
            <Modal.Body>
                {props.body}
            </Modal.Body>
        </Modal>
    )
}
