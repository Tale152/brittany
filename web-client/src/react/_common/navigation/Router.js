/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
