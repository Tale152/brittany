import Button from 'react-bootstrap/Button'
import RedirectTo from './Redirect'

export default function RedirectButton(props) {

  if(props.redirect === true){
    return RedirectTo(props.destination)
  } else {
    return(
      <Button
        onClick = { () => props.onClick() }
        className = "col-lg-12 my-2"
        variant = "primary"
        style = { props.isLoading ? { pointerEvents: "none", opacity: "0.4" } : {} }
      >
        {props.text}
      </Button>
    )
  }
}
