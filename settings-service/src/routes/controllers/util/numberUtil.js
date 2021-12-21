function isValidNumber(num){
    return num !== null && num !== undefined && !isNaN(num)
}

module.exports = {
    isValidNumber
}
