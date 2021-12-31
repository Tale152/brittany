export const setFarmersList = (list) => {
    return {
        type: "SET_FARMERS_LIST",
        payload: list
    }
}

export const setSelectedFarmer = (selected) => {
    return {
        type: "SET_SELECTED_FARMER",
        payload: selected
    }
}