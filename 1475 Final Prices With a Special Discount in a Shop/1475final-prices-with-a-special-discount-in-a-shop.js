/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function(prices) {
    let n=prices.length;
    let res=[];
    for(let i=0;i<n;i++){
        let dis=0;
        for(let j=i+1;j<n;j++){
            if(prices[j]<=prices[i]){
                dis=prices[j];
                break;
            }
        }
        res.push(prices[i]-dis);
    }
    return res;
};