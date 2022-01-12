var initialState = {
    list: [],
    selected: null
}

const environmentsReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_ENVIRONMENT_LIST': return Object.assign({}, state, {
            list: action.payload
        })
        case 'SET_SELECTED_ENVIRONMENT': return Object.assign({}, state, {
            selected: action.payload
        })
        default: return state;
    }
}
export default environmentsReducer
