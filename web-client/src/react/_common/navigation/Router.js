import {
    BrowserRouter,
    Routes as Switch,
    Route,
} from 'react-router-dom'
  
import FarmerLogin from '../../farmerLogin/Login'
import Register from '../../register/Register'
import Greenhouses from '../../greenhouses/Greenhouses'
import Farmers from '../../farmers/Farmers'
import Settings from '../../settings/Settings'
import Data from '../../data/Data'
  
export default function Router() {
  return (
    <BrowserRouter>
      <Switch>
        <Route path="/" element={<FarmerLogin/>} />
        <Route path="/register" element={<Register/>} />
        <Route path="/greenhouses" element={<Greenhouses/>} />
        <Route path="/farmers" element={<Farmers/>} />
        <Route path="/settings" element={<Settings/>} />
        <Route path="/data" element={<Data/>} />
      </Switch>
    </BrowserRouter>
  )
}
