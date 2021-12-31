export const setGreenhouseList = (list) => {
    return {
        type: "SET_GREENHOUSE_LIST",
        payload: list
    }
}

export const setSelectedGreenhouse = (selected) => {
    return {
        type: "SET_SELECTED_GREENHOUSE",
        payload: selected
    }
}
