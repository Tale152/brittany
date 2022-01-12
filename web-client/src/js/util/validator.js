export function isNonEmptyString(s){
    return s !== null && s!== undefined && typeof s === 'string' && s.trim().length > 0
}
