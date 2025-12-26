/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    let res=[];
    let pu="Push";
    let po="Pop";
    let i=0;
    let j=1;
    while(i<target.length){
        while(j<target[i]){
            res.push(pu);
            res.push(po);
            j++;
        }
        res.push(pu);
        j++;
        i++;
    }
    return res;
};