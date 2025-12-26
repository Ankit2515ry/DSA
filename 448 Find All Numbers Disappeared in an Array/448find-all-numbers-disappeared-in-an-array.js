/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    // let n=nums.length;
    // let arr=new Array(n+1).fill(0);
    // for(let x of nums)arr[x]++;
    // let res=[];
    // for(let i=1;i<n+1;i++){
    //     if(arr[i]==0)res.push(i);
    // }
    // return res;
    let n=nums.length;
    let res=[];
    let st=new Set(nums);
    for(let i=1;i<=n;i++){
        if(!st.has(i))res.push(i);
    }
    return res;
};