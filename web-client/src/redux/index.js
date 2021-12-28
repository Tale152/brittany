import { combineReducers } from 'redux'

import identityReducer from './identity/reducer'

const allReducers = combineReducers({
    identity: identityReducer,
})

export default allReducers