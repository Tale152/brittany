import { combineReducers } from 'redux'

import identityReducer from './identity/reducer'
import utilReducer from './util/reducer'
import greenhousesReducer from './greenhouses/reducer'
import environmentsReducer from './environments/reducer'
import farmersReducer from './farmers/reducer'
import settingsReducer from './settings/reducer'
import persistenceReducer from './persistence/reducer'

const allReducers = combineReducers({
    identity: identityReducer,
    util: utilReducer,
    greenhouses: greenhousesReducer,
    environments: environmentsReducer,
    farmers: farmersReducer,
    settings: settingsReducer,
    persistence: persistenceReducer,
})

export default allReducers