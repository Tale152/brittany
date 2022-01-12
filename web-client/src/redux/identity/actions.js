export const setToken = (token) => {
    return {
        type: "SET_TOKEN",
        payload: token
    }
}

export const setOrganizationName = (name) => {
    return {
        type: "SET_ORGANIZATION_NAME",
        payload: name
    }
}
