import { useState } from 'react'

import ExampleTextProps from '../_common/ExampleTextProps'
import RedirectButton from '../_common/navigation/RedirectButton'

import Button from 'react-bootstrap/Button'
import $ from 'jquery'
import { persistenceService } from '../../conf'

export default function Homepage() {

  const [goAuth, setGoToAuth] = useState(false)

  return (
    <>
      <ExampleTextProps text={"Homepage"} />
      <RedirectButton
        text={"Authentication"}
        redirect={goAuth}
        destination={""}
        onClick={() => setGoToAuth(true)}
      />
      <Button onClick={() => {
        $.get(persistenceService + "/temperature/exists?value=69")
        .done(function (result) {
            console.log("success")
            console.log(result)
        })
        .fail(function (result) {
          console.log("fail")
          console.log(result)
        })
      }}>Value exists</Button>
    </>
  )
  
}
