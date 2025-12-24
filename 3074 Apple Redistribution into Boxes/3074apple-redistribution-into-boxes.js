/**
 * @param {number[]} apple
 * @param {number[]} capacity
 * @return {number}
 */
var minimumBoxes = function(apple, capacity) {
    let applecount=0;
    for(let i=0;i<apple.length;i++){
        applecount=applecount+apple[i];
    }
    capacity.sort((a, b) => a - b);
    let res=0;
    for(let i=capacity.length-1;i>=0;i--){
        if(applecount>capacity[i]){
            applecount=applecount-capacity[i];
            res++;
        }else{
            res++;
            break;
        }
    }
    return res;
};