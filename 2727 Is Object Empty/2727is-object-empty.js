/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    const a=Object.keys(obj)
    if(a.length==0)return true
    return false
};