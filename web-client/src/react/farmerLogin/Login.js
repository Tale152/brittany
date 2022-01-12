import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import LoginPage from './components/LoginPage'

export default function FarmerLogin() {

  let token = useSelector(state => state.identity.token)

  if (token === null) {
      return <LoginPage />
  } else {
      return <RedirectTo destination={"greenhouses"} />
  }
  
}
