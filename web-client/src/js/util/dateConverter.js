function correctValue(v){
    return parseInt(v) > 9 ? v : ("0" + v)
}

export function convertDate(date){
    return date.getFullYear() + "-" + correctValue(date.getMonth() + 1) + "-" + correctValue(date.getDate())
}
