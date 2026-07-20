class Solution {
public:
    long long mod=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long x=0;
        long long y=0;
        long long res=0;
        for(auto it:nums){
            if(it<a){
                res=(res+x+y)%mod;
            }else if(it>=a&&it<=b){
                res=(res+y)%mod;
                x++;
            }else{
                y++;
            }
        }
        return res;
    }
};