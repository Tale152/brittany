import Button from 'react-bootstrap/Button'

export default function FormButton(props){
    return (
        <Button
            style = { props.isLoading ? { pointerEvents: "none", opacity: "0.4" } : {} }
            className = "col-lg-12 my-2"
            variant = "primary"
            block = "true"
            onClick = { props.onClick }
        >
            { props.text }
        </Button>
    )
}
