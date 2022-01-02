var initialState = {
    list: [],
    selected: null
}

const settingsReducer = (state = initialState, action) => {
    switch(action.type){
        case 'SET_SETTINGS_LIST': return Object.assign({}, state, {
            list: action.payload
        })
        case 'SET_SELECTED_SETTINGS': return Object.assign({}, state, {
            selected: action.payload
        })
        default: return state;
    }
}
export default settingsReducer
