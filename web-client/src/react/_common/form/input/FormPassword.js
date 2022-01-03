import FormInput from './FormInput'

export default function FormPassword(props) {

    return (
        <FormInput
            text={props.text}
            type="password"
            placeholder = {props.placeholder}
            onChange = {props.onChange}
            onEnter={props.onEnter}
        />   
    )
  
}