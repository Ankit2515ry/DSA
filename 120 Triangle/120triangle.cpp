class Solution {
public:
    //int res=INT_MAX;
    // void solve(int i,int j,int sum,vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     int m=triangle[i].size();
    //     if(i>=n||j>=m)return;
    //     sum+=triangle[i][j];
    //     if(i==n-1){
    //         res=min(res,sum);
    //         sum-=triangle[i][j];
    //         return ;
    //     }
    //     solve(i+1,j,sum,triangle);
    //     solve(i+1,j+1,sum,triangle);
    //     sum-=triangle[i][j];
    // }
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& triangle){
        int n=triangle.size();
        int m=triangle[i].size();
        if(i>=n||j>=m)return INT_MAX;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        if(i==n-1){
            return dp[i][j]=triangle[i][j];
        }
        int d=solve(i+1,j,triangle);
        int r=solve(i+1,j+1,triangle);
        return dp[i][j]=min(d,r)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        dp.assign(n,vector<int>(m+1,INT_MIN));
        return solve(0,0,triangle);
        //solve(0,0,0,triangle);
        //return res;
    }
};