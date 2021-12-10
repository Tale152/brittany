import 'bootstrap/dist/css/bootstrap.min.css'
import React from 'react'

import { Provider } from 'react-redux'
import { createStore } from 'redux'
import allReducers from '../redux'

import Router from './_common/navigation/Router'

const store = createStore(
  allReducers,
  window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__()
)

export default function App() {

  return (
    <Provider store={store}>
        <React.Fragment>
            <Router/>
        </React.Fragment>
    </Provider>
  )

}
