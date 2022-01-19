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
