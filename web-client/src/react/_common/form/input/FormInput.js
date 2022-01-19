import { useSelector } from 'react-redux'
import Form from 'react-bootstrap/Form'

export default function FormInput(props){
    return (
        <>
            <h3>{props.text}</h3>
            <Form.Control
                style={useSelector(state => state.util.isLoading) ? { pointerEvents: "none", opacity: "0.4" } : {}}
                className = "border-2 border-dark"
                type={props.type}
                onChange={e => props.onChange(e.target.value)}
                placeholder={props.placeholder}
                onKeyPress={event => { if (event.charCode === 13) props.onEnter() }}
            />
        </>
    )
}
