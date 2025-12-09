class Solution {
public:
    int res=0;
    vector<vector<int>>dp;
    int solve(int n,int m,int i,int j,vector<vector<int>>&obstacleGrid){
        if(i>=n||j>=m)return 0;
        if(i==n-1&&j==m-1){
            //res++;
            return 1;
        }
        if(obstacleGrid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int r=solve(n,m,i+1,j,obstacleGrid);
        int d=solve(n,m,i,j+1,obstacleGrid);
        return dp[i][j]=r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        //dp.assign(n+1,vector<int>(m+1,-1));
        vector<vector<int>>dpp(n,vector<int>(m,0));
        dpp[0][0]=1;
        if(obstacleGrid[0][0] == 1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dpp[i][j]=0;
                    continue;
                }
                if(i==0&&j==0)continue;
                int l=(j>0)?dpp[i][j-1]:0;
                int u=(i>0)?dpp[i-1][j]:0;
                dpp[i][j]=l+u;   
            }
        }
        return dpp[n-1][m-1];
        //return solve(n,m,0,0,obstacleGrid);
        //return res;
    }
};