class Solution {
public:
    //int res=INT_MAX;
    // void solve(int i,int j,int sum,vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     if(i>=n||j>=n||i<0||j<0)return ;
    //     sum+=matrix[i][j];
    //     if(i==n-1){
    //         res=min(res,sum);
    //         return;
    //     }
    //     solve(i+1,j-1,sum,matrix);
    //     solve(i+1,j,sum,matrix);
    //     solve(i+1,j+1,sum,matrix);
    // }
    vector<vector<int>>dp;
    // int solve(int i,int j,vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     if(i>=n||j>=n||i<0||j<0)return INT_MAX;
    //     if(dp[i][j]!=INT_MIN)return dp[i][j];
    //     if(i==n-1){
    //         return dp[i][j]=matrix[i][j];
    //     }
    //     int l=solve(i+1,j-1,matrix);
    //     int m=solve(i+1,j,matrix);
    //     int r=solve(i+1,j+1,matrix);
    //     return dp[i][j]=matrix[i][j]+min({l,m,r});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // dp.assign(n,vector<int>(n,INT_MIN));
        // int res=INT_MAX;
        // for(int i=0;i<n;i++){
        //     res=min(res,solve(0,i,matrix));
        // }
        // return res;
        dp=matrix;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int a=(j>0)?dp[i+1][j-1]:INT_MAX;
                int b=dp[i+1][j];
                int c=(j<n-1)?dp[i+1][j+1]:INT_MAX;
                dp[i][j]+=min({a,b,c});
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)res=min(res,dp[0][i]);
        return res;
    }
};