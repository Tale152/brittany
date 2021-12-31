var initialState = {
    token: null,
    organizationName: "",
}

const tokenReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_TOKEN': return Object.assign({}, state, {
            token: action.payload
        })
        case 'SET_ORGANIZATION_NAME': return Object.assign({}, state, {
            organizationName: action.payload
        })
        default: return state;
    }
}
export default tokenReducer
