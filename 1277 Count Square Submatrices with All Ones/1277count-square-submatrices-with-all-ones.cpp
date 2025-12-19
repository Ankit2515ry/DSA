class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        if(i>=n||j>=m)return 0;
        if(mat[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0;
        int b=0;
        int c=0;
        if(mat[i][j]==1){
            a=solve(i+1,j,mat);
            b=solve(i,j+1,mat);
            c=solve(i+1,j+1,mat);
        }
        return dp[i][j]=min({a,b,c})+1;
    }
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // int res=0;
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==1)dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
        //         res+=dp[i+1][j+1];
        //     }
        // }
        // // for(int i=0;i<n;i++){
        // //     for(int j=0;j<m;j++){
        // //         cout<<dp[i+1][j+1]<<" ";
        // //     }
        // //     cout<<endl;
        // // }
        // return res;
        int ans = 0;
        dp.assign(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans += solve(i, j, mat);
        return ans;
    }
};