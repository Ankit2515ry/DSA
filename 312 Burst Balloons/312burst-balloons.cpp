class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&nums){
        if(j-i<=1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int temp=0;
        for(int k=i+1;k<j;k++){
            int x=nums[i]*nums[k]*nums[j];
            temp=max(temp,solve(i,k,nums)+solve(k,j,nums)+x);
        }
        return dp[i][j]=temp;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,nums);
    }
};