import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import GreenhousesPage from './components/GreenhousesPage'

export default function Greenhouses() {

  let token = useSelector(state => state.identity.token)

  if (token !== null) {
      return <GreenhousesPage />
  } else {
      return <RedirectTo destination={""} />
  }
  
}
