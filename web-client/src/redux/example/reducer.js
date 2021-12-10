var initialState = {
    flag: false,
}

const exampleReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_FLAG': state.flag = action.payload; return state;
        default: return state;
    }
}
export default exampleReducer
