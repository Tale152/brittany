import {
    BrowserRouter,
    Routes as Switch,
    Route,
} from 'react-router-dom'
  
import FarmerLogin from '../../farmerLogin/FarmerLogin'
  
export default function Router() {
  return (
    <BrowserRouter>
      <Switch>
        <Route path="/" element={<FarmerLogin/>} />
      </Switch>
    </BrowserRouter>
  )
}
