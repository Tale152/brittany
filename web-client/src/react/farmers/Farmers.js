import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import FarmersPage from './components/FarmersPage'

export default function Farmers() {

  let token = useSelector(state => state.identity.token)

  if (token !== null) {
      return <FarmersPage />
  } else {
      return <RedirectTo destination={""} />
  }
  
}
