/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let a=arr1.concat(arr2);
    let m={};
    a.forEach((obj)=>{
        let id=obj.id;
        if(!m[id]){
            m[id]={...obj};
        }else{
            m[id]={...m[id],...obj};
        }
    });
    return Object.values(m);
    // const map = new Map();
    // for(const obj of arr1) map.set(obj.id, obj);
    // for(const obj of arr2) {
    //     if(!map.has(obj.id)) map.set(obj.id, obj);
    //     else {
    //         const prevObj = map.get(obj.id);
    //         for(const key of Object.keys(obj)) prevObj[key] = obj[key];
    //     }
    // }
    // const res = new Array();
    // for(let key of map.keys()) res.push(map.get(key));
    // return res.sort(); 
};