var initialState = {
    list: [],
    selected: null
}

const greenhousesReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_LIST': return Object.assign({}, state, {
            list: action.payload
        })
        case 'SET_SELECTED': return Object.assign({}, state, {
            selected: action.payload
        })
        default: return state;
    }
}
export default greenhousesReducer
