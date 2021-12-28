import { combineReducers } from 'redux'

import identityReducer from './identity/reducer'
import utilReducer from './util/reducer'

const allReducers = combineReducers({
    identity: identityReducer,
    util: utilReducer,
})

export default allReducers