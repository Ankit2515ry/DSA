class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int a=amount[0];
        int b=amount[1];
        int c=amount[2];
        int res=0;
        int temp=a+b;
        if(temp<=c){
            int d=max(temp,c)-min(temp,c);
            res+=min(temp,c);
            res+=d;
        }else{
            int d=max(temp,c)-min(temp,c);
            res+=min(temp,c);
            if(d%2!=0)res++;
            res+=(d/2);
        }
        return res;
    }
};