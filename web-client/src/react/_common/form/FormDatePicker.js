import DatePicker from 'react-datepicker'
import 'react-datepicker/dist/react-datepicker.css'

export default function FormDatePicker(props){
    return (
        <>
            <h3>{props.text}</h3>
            <DatePicker 
                className = "border-2 border-dark rounded"
                selected = { props.selected } 
                onChange = { props.onChange }
            />
        </>
    )
}