export default function formatTime(h, m){
    return applyLeadingZero(h.toString()) + ":" + applyLeadingZero(m.toString())
}

function applyLeadingZero(v){
    return v.length === 1 ? "0" + v : v
}