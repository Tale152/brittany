var initialState = {
    token: null,
}

const tokenReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_TOKEN': state.token = action.payload; return state;
        default: return state;
    }
}
export default tokenReducer
