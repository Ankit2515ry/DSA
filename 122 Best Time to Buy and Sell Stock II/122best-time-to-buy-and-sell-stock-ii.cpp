class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mi=prices[0];
        int ma=0;
        for(auto &it:prices){
            ma=max(ma,it);
            if(it-ma<=0){
                res+=ma-mi;
                mi=it;
                ma=it;
            }
        }
        return res;
    }
};