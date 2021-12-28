var initialState = {
    isLoading: false
}

const utilReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_IS_LOADING': state.isLoading = action.payload; return state;
        default: return state;
    }
}

export default utilReducer