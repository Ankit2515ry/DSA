class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=n-2;
        while(n>0){
            ans+=nums[i];
            n-=3;
            i-=2;
        }
        return ans;
    }
};