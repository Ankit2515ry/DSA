class Solution {
public:
    vector<int>dp;
    int solve(int i,vector<int>&nums){
        if (i >= nums.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i] + solve(i + 2, nums);
        int skip = solve(i + 1, nums);
        dp[i]=max(pick, skip);
        //cout<<dp[i]<<" ";
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // dp.assign(n+1,-1);
        // return solve(0,nums);
        vector<int>dpp(n+2,0);
        if(n==0)return 0;
        if(n==1)return nums[0];
        int a=0;
        int b=0;
        int c=0;
        for(int i=n-1;i>=0;i--){
            //dpp[i]=max(dpp[i+1],nums[i]+dpp[i+2]);
            c=max(a,nums[i]+b);
            b=a;
            a=c;
        }
        //return dpp[0];
        return c;
    }
};