class Solution {
public:
    vector<long long >dp;
    long long solve(vector<vector<int>>& q,int i){
        if(i>=q.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long a=q[i][0]+solve(q,i+q[i][1]+1);
        long long b=solve(q,i+1);
        return dp[i]=max(a,b);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        dp.assign(n,-1);
        return solve(q,0);
    }
};