class Solution {
public:
//in recursion take pair so track of both length and no of sequences done 
//if length is greates of one then return as it is
//if same return {length,no of length from one + no of length from second}
//pair can't compare directley need to apply .first,.second then compare individual element of pair
//memo solution -> assign dp of pairs with {-1,-1};
    vector<vector<pair<int,int>>>dp;
    pair<int,int> solve(int i,int j,vector<int>& nums){
        int n=nums.size();
        if(i==n)return {0,1};
        pair<int,int> b={0,0};
        if(dp[i][j+1].first!=-1&&dp[i][j+1].second!=-1)return dp[i][j+1];
        if(j==-1||nums[j]<nums[i]){
           auto k=solve(i+1,i,nums);
           b={k.first+1,k.second};
        }
        auto a=solve(i+1,j,nums);
        if(a.first==b.first)return dp[i][j+1]={a.first,a.second+b.second};
        pair<int,int>k=(a.first<b.first)?b:a;
        return dp[i][j+1]=k;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1,vector<pair<int,int>>(n+1,{-1,-1}));
        auto res=solve(0,-1,nums);
        return res.second;
    }
};