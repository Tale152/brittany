import { combineReducers } from 'redux'

import identityReducer from './identity/reducer'
import utilReducer from './util/reducer'
import greenhousesReducer from './greenhouses/reducer'
import environmentsReducer from './environments/reducer'

const allReducers = combineReducers({
    identity: identityReducer,
    util: utilReducer,
    greenhouses: greenhousesReducer,
    environments: environmentsReducer
})

export default allReducers