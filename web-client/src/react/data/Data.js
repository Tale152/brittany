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
