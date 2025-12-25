/**
 * @param {number[]} happiness
 * @param {number} k
 * @return {number}
 */
var maximumHappinessSum = function(h, k) {
    h.sort((a,b)=>b-a);
    let res=0;
    let t=0;
    for(let i=0;i<k;i++){
        let x=0;
        x=h[i]-t;
        if(x<0)break;
        res=res+x;
        t++;
    }
    return res;
};
// /**
//  * @param {number[]} happiness
//  * @param {number} k
//  * @return {number}
//  */
// var maximumHappinessSum = function(h, k) {
//     h.sort((a,b)=>b-a);
//     let res=0;
//     let t=0;
//     // for(let i=0;i<h.length;i++){
//     //     console.log(h[i]);
//     // }
//     for(let i=0;i<k;i++){
//         let x=h[i]-t;
//         let z= x > 0 ? x : 0;
//         res=res+z;//Math.max(x,0);
//         t++;
//     }
//     return res;
// };