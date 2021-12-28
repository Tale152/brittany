import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import FarmerLoginPage from './components/FarmerLoginPage'

export default function FarmerLogin() {

  let token = useSelector(state => state.identity.token)

  if (token === null) {
      return <FarmerLoginPage />
  } else {
      return <RedirectTo destination={"home"} />
  }
  
}
