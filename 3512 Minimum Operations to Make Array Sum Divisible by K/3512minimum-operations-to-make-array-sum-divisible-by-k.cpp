class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(auto &it:nums)sum+=it;
        int res=sum%k;
        return res;
    }
};