/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let c2=0;
    let c5=0;
    while(n>1){
        let a=n;
        while(a%2==0&&a!=0){
            if(n%2==0)c2++;
            else break;
            a=a/2;
        }
        a=n;
        while(a%5==0&&a!=0){
            if(n%5==0)c5++;
            else break;
            a=a/5;
        }
        n--;
    }
    return Math.min(c2,c5);
};