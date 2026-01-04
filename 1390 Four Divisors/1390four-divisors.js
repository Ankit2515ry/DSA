/**
 * @param {number[]} nums
 * @return {number}
 */
var sumFourDivisors = function(nums) {
    let res=0;
    for(let i=0;i<nums.length;i++){
        let n=nums[i];
        let c=0;
        let sum=0;
        for(let j=1;j*j<=n;j++){
            if(n%j==0){
                if(j==n/j){
                    c++;
                    sum+=j;
                }else{
                    c+=2;
                    sum+=j;
                    sum+=n/j;
                }
            }
        }
        //console.log(c);
        if(c==4){
            res+=sum;
        }
    }
    return res;
};