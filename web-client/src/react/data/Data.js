import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import DataPage from './components/DataPage'

export default function Data() {

  let token = useSelector(state => state.identity.token)
  let environment = useSelector(state => state.environments.selected)

  if (token !== null && environment !== null) {
      return <DataPage />
  } else {
      return <RedirectTo destination = { "" } />
  }
  
}
