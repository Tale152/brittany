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

import 'bootstrap/dist/css/bootstrap.min.css'
import React from 'react'
import { positions, Provider as AlertProvider } from 'react-alert'
import AlertTemplate from 'react-alert-template-basic'

import { Provider } from 'react-redux'
import { createStore } from 'redux'
import allReducers from '../redux'

import Router from './_common/navigation/Router'

const options = {
  timeout: 3000,
  position: positions.TOP_CENTER
}

const store = createStore(
  allReducers,
  window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__()
)

export default function App() {

  return (
    <Provider store={store}>
      <AlertProvider template={AlertTemplate} {...options}>
        <React.Fragment>
            <Router/>
        </React.Fragment>
      </AlertProvider>
    </Provider>
  )

}
