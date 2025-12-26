/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function(customers) {
    let n=customers.length;
    let su=new Array(n+1).fill(0);
    for(let i=n-1;i>=0;i--){
        if(customers[i]=='Y'){
            su[i]=su[i+1]+1;
        }else{
            su[i]=su[i+1];
        }
    }
    let pr=new Array(n+1).fill(0);
    for(let i=0;i<n;i++){
        if(customers[i]=='N'){
            pr[i+1]=pr[i]+1;
        }else{
            pr[i+1]=pr[i];
        }
    }
    let penalty=Infinity;
    let ind=0;
    for(let i=0;i<=n;i++){
        if(penalty>su[i]+pr[i]){
            ind=i;
            penalty=su[i]+pr[i];
        }
    }
    return ind;
};