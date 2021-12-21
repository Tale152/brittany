function isValidString(str){
    return str !== null && str !== undefined && str.trim() !== ""
}

module.exports = {
    isValidString
}
