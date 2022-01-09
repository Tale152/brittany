var initialState = {
    temperature: [],
    airHumidity: []
}

const persistenceReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_TEMPERATURE': return Object.assign({}, state, {
            temperature: action.payload
        })
        case 'SET_AIR_HUMIDITY': return Object.assign({}, state, {
            airHumidity: action.payload
        })
        default: return state;
    }
}
export default persistenceReducer
