import FormButton from './FormButton'

export default function FormLogin(props){
    return (
        <FormButton
            onClick = { props.onClick }
            text = { props.text }
        />
    )
}