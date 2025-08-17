class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        long long res=0;
        for(auto it:nums)res+=it;
        vector<long long>best(k,LLONG_MIN);
        long long dp=0;
        long long prefix=0;
        best[0]=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int x=((prefix%k)+k)%k;
            dp=max(dp,best[x]+prefix);
            best[x]=max(best[x],dp-prefix);
        }
        return res-dp;
    }
};