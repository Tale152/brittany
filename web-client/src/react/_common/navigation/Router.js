import {
    BrowserRouter,
    Routes as Switch,
    Route,
} from 'react-router-dom'
  
import FarmerLogin from '../../farmerLogin/FarmerLogin'
import Home from '../../home/Home'
  
export default function Router() {
  return (
    <BrowserRouter>
      <Switch>
        <Route path="/" element={<FarmerLogin/>} />
        <Route path="/home" element={<Home/>} />
      </Switch>
    </BrowserRouter>
  )
}
