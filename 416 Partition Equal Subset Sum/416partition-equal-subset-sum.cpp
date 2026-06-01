class Solution {
public:
    int maxsum=0;
    vector<vector<int>>dp;
    bool solve(int i,int sum,vector<int>&nums){
        if(i>=nums.size()){
            if(sum==maxsum)return true;
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool a=solve(i+1,sum,nums);
        bool b=solve(i+1,sum+nums[i],nums);
        dp[i][sum]=a||b;
        //cout<<dp[i][sum]<<" ";
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        maxsum=accumulate(nums.begin(),nums.end(),0);
        if(maxsum%2==1)return false;
        maxsum/=2;
        // dp.assign(nums.size(),vector<int>(2*maxsum,-1));
        // return solve(0,0,nums);
        bitset<20001>bst;
        bst[0]=1;
        for(auto it:nums){
            bst|=(bst<<it);
        }
        return bst[maxsum];
    }
};