import FormButton from './FormButton'

export default function FormLogin(props){
    return (
        <FormButton
            isLoading = { props.isLoading }
            onClick = { props.onClick }
            text = { props.text }
        />
    )
}