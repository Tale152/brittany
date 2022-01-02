export const setSettingsList = (list) => {
    return {
        type: "SET_SETTINGS_LIST",
        payload: list
    }
}

export const setSelectedSetting = (selected) => {
    return {
        type: "SET_SELECTED_SETTINGS",
        payload: selected
    }
}
