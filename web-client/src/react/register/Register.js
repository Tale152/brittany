import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import RegisterPage from './components/RegisterPage'

export default function Register() {

  let token = useSelector(state => state.identity.token)

  if (token === null) {
      return <RegisterPage />
  } else {
      return <RedirectTo destination={"home"} />
  }
  
}
