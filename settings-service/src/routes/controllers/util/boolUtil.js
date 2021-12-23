function isValidBoolean(b){
    return b !== null && b !== undefined && typeof b == "boolean"
}

module.exports = {
    isValidBoolean
}
