import {
    BrowserRouter,
    Routes as Switch,
    Route,
} from 'react-router-dom'
  
import Authentication from '../../authentication/Authentication'
import HomePage from "../../homepage/Homepage"
  
export default function Router() {
  return (
    <BrowserRouter>
      <Switch>
        <Route path="/" element={<Authentication/>} />
        <Route path="/home" element={<HomePage/>} />
      </Switch>
    </BrowserRouter>
  )
}
