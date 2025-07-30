class Solution {
public:
    bool winnerOfGame(string colors) {
       int a=0;
       int b=0;
       int tempa=0;
       int tempb=0;
       for(auto it:colors){
        if(it=='A'){
            tempa++;
            if(tempa>=3)a++;
            tempb=0;
        }
        else{
            tempb++;
            if(tempb>=3)b++;
            tempa=0;
        }
       } 
       if(a>b)return true;
       return false;
    }
};