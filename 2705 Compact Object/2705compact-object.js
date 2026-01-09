/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)){
        return obj.filter(Boolean).map(compactObject);
    }
    if(obj!=null&&typeof obj==="object"){
        const res={};
        for(let key in obj){
            const v=compactObject(obj[key]);
            if(Boolean(v)){
                res[key]=v;
            }
        }
        return res;
    }
    return obj;
};