var initialState = {
    list: [],
    selected: null
}

const farmersReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_FARMERS_LIST': return Object.assign({}, state, {
            list: action.payload
        })
        case 'SET_SELECTED_FARMER': return Object.assign({}, state, {
            selected: action.payload
        })
        default: return state;
    }
}
export default farmersReducer
