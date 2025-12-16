class Solution {
public:
    vector<vector<pair<int,vector<int>>>>dp;
    pair<int,vector<int>> solve(int i,int j,vector<int>& nums){
        int n=nums.size();
        if(i==n)return {0,{}};
        if(dp[i][j+1].first!=-1)return dp[i][j+1];
        pair<int,vector<int>> a={0,{}};
        if(j==-1||nums[i]%nums[j]==0){
            auto x=solve(i+1,i,nums);
            a=x;
            a.first+=1;
            a.second.push_back(nums[i]);
        }
        auto b=solve(i+1,j,nums);
        if(a.first>b.first)return dp[i][j+1]=a;
        return dp[i][j+1]=b;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        dp.assign(n,vector<pair<int,vector<int>>>(n+1,{-1,{}}));
        auto a=solve(0,-1,nums);
        //cout<<a.first;
        reverse(a.second.begin(),a.second.end());
        return a.second;
    }
};