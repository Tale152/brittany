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
