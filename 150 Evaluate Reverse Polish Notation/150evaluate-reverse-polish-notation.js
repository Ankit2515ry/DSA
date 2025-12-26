/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let arr=[];
    let i=0;
    let n=tokens.length;
    while(i<n){
        if(!isNaN(tokens[i])){
            arr.push(Number(tokens[i]));
        }else{
            let b=arr[arr.length-1];
            arr.pop();
            let a=arr[arr.length-1];
            arr.pop();
            if(tokens[i]==="+"){
                arr.push(a+b);
                //console.log(a+b);
            }
            else if(tokens[i]==="-"){
                arr.push(a-b);
                //console.log(a-b);
            }
            else if(tokens[i]==="*"){
                arr.push(a*b);
                //console.log(a*b);
            }
            else if(tokens[i]==="/"){
                arr.push(Math.trunc(a/b));
                //console.log(Math.trunc(a/b));
            }
        }
        i++;
    }
    //for(let x of arr)console.log(x);
    return arr[0];
};