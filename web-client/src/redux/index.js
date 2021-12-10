import { combineReducers } from 'redux'

import exampleReducer from './example/reducer'

const allReducers = combineReducers({
    example: exampleReducer,
})

export default allReducers