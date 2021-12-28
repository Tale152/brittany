import { useSelector } from 'react-redux'

import RedirectTo from '../_common/navigation/Redirect'

export default function Home() {

  if (useSelector(state => state.identity.token) !== null) {
      return <p>home</p>
  } else {
      return <RedirectTo destination={""} />
  }
  
}
