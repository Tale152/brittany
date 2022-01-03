import FormInput from './FormInput'

export default function FormText(props) {

    return (
        <FormInput
            text={props.text}
            type="text"
            placeholder = {props.placeholder}
            onChange = {props.onChange}
            onEnter={props.onEnter}
        />   
    )
  
}