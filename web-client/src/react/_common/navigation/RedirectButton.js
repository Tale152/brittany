import { useState } from 'react'
import { useSelector } from 'react-redux'
import Button from 'react-bootstrap/Button'

import RedirectTo from './Redirect'

export default function RedirectButton(props) {

  const isLoading = useSelector(state => state.util.isLoading)
  const [goToRedirect, setGoToRedirect] = useState(false)

  if(goToRedirect === true){
    return <RedirectTo destination={ props.destination } />
  } else {
    return(
      <Button
        onClick = { () => setGoToRedirect(true) }
        className = "col-lg-12 my-2"
        variant = "primary"
        style = { isLoading ? { pointerEvents: "none", opacity: "0.4" } : {} }
      >
        {props.text}
      </Button>
    )
  }
}
