class Solution {
public:
    // int res=0;
    // void solve(int i,int sum,vector<int>& nums, int target){
    //     if(i>=nums.size()){
    //         if(sum==target)res++;
    //         return;
    //     }
    //     solve(i+1,sum+nums[i],nums,target);
    //     solve(i+1,sum-nums[i],nums,target);
    // }
    // vector<vector<vector<int>>>dp;
    // int solve(int i,int sum,vector<int>& nums, int target){
    //     if(i>=nums.size()){
    //         if(sum==target)return 1;
    //         return 0;
    //     }
    //     int s=(sum<0)?1:0;
    //     if(dp[i][abs(sum)][s]!=-1)return dp[i][abs(sum)][s];
    //     int x=solve(i+1,sum+nums[i],nums,target);
    //     int y=solve(i+1,sum-nums[i],nums,target);
    //     return dp[i][abs(sum)][s]=x+y;
    // }
    vector<vector<int>>dp;
    int of=1000;
    int solve(int i,int sum,vector<int>& nums, int target){
        if(i>=nums.size()){
            if(sum==target)return 1;
            return 0;
        }
        if(dp[i][sum+of]!=-1)return dp[i][sum+of];
        int x=solve(i+1,sum+nums[i],nums,target);
        int y=solve(i+1,sum-nums[i],nums,target);
        return dp[i][sum+of]=x+y;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // solve(0,0,nums,target);
        // return res;
        int n=nums.size();
        //dp.assign(n,vector<vector<int>>(20001,vector<int>(2,-1)));
        dp.assign(n,vector<int>(2001,-1));
        return solve(0,0,nums,target);
    }
};