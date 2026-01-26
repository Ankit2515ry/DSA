/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    arr.sort((a,b)=>a-b);
    console.log(arr);
    let d=Infinity;
    let n=arr.length;
    for(let i=1;i<n;i++){
        d=Math.min(d,arr[i]-arr[i-1]);
    }
    let res=new Array();
    for(let i=1;i<n;i++){
        let x=arr[i]-arr[i-1];
        if(x===d)res.push([arr[i-1],arr[i]]);
    }
    return res;
};