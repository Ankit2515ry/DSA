class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res(n,0);
        int temp=n/2;
        for(int i=0;i<temp;i++){
            res[i]=-(i+1);
        }
        int x=temp;
        int i=n-1;
        for(i;i>temp;i--){
            res[i]=x;
            x--;
        }
        if(n%2==0)res[i]=x;
        return res;
    }
};