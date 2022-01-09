export const setTemperature = (temperature) => {
    return {
        type: "SET_TEMPERATURE",
        payload: temperature
    }
}

export const setAirHumidity = (airHumidity) => {
    return {
        type: "SET_AIR_HUMIDITY",
        payload: airHumidity
    }
}
