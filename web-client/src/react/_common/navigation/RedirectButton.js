import { useState } from 'react'
import CustomCenteredButton from '../CustomCenteredButton'

import RedirectTo from './Redirect'

export default function RedirectButton(props) {

  const [goToRedirect, setGoToRedirect] = useState(false)

  if(goToRedirect === true){
    return <RedirectTo destination={ props.destination } />
  } else {
    return(
      <CustomCenteredButton text={ props.text }  onClick = { () => setGoToRedirect(true) } />
    )
  }
}
