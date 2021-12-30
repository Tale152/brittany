export const setList = (list) => {
    return {
        type: "SET_LIST",
        payload: list
    }
}

export const setSelected = (selected) => {
    return {
        type: "SET_SELECTED",
        payload: selected
    }
}
