import Button from 'react-bootstrap/Button'
import RedirectTo from './Redirect'

export default function RedirectButton(props) {

  if(props.redirect === true){
    return RedirectTo(props.destination)
  } else {
    return <Button onClick={() => props.onClick()}>{props.text}</Button>
  }
}
