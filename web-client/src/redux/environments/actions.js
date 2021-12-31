export const setEnvironmentList = (list) => {
    return {
        type: "SET_ENVIRONMENT_LIST",
        payload: list
    }
}

export const setSelectedEnvironment = (selected) => {
    return {
        type: "SET_SELECTED_ENVIRONMENT",
        payload: selected
    }
}
