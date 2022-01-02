import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'
import SettingsPage from './components/SettingsPage'

export default function Greenhouses() {

  let token = useSelector(state => state.identity.token)
  let environment = useSelector(state => state.environments.selected)

  if (token !== null && environment !== null) {
      return <SettingsPage />
  } else {
      return <RedirectTo destination={""} />
  }
  
}
