class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ma=INT_MIN;
        int mi=INT_MAX;
        int n=nums.size();
        for(auto &it:nums){
            ma=max(ma,it);
            mi=min(mi,it);
        }
        long long res=1LL*k*(ma-mi);
        return res;
    }
};