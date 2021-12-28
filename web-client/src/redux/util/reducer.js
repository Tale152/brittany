var initialState = {
    isLoading: false
}

const utilReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_IS_LOADING': return Object.assign({}, state, {
            isLoading: action.payload
        })
        default: return state;
    }
}

export default utilReducer