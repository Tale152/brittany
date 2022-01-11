import DatePicker from 'react-datepicker'
import 'react-datepicker/dist/react-datepicker.css'

export default function FormDatePicker(props){
    return (
        <>
            <h3>{props.text}</h3>
            <DatePicker selected = { props.selected } onChange = { props.onChange } />
        </>
    )
}