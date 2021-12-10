import { useState } from 'react'

import ExampleFlagButton from '../_common/ExampleFlagButton'
import ExampleTextProps from '../_common/ExampleTextProps'
import AuthForm from './components/AuthForm'
import RedirectButton from '../_common/navigation/RedirectButton'
import login from '../../js/login'

export default function Authentication() {

  const [goToHome, setGoToHome] = useState(false)

  return (
    <>
      <ExampleTextProps text={"Authentication page"} />
      <AuthForm onClick={() => login()} />
      <RedirectButton
        text={"Homepage"}
        redirect={goToHome}
        destination={"home"}
        onClick={() => setGoToHome(true)}
      />
      <ExampleFlagButton/>
    </>
  )

}
