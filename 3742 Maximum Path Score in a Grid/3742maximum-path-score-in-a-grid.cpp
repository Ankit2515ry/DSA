class Solution {
public:
    int dfs(int i,int j,int c,vector<vector<vector<int>>>&dp,vector<vector<int>>& grid,int k){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n||j>=m)return -1e9;
        int cc=0;
        if(grid[i][j]==1||grid[i][j]==2)cc=1;
        int nc=c+cc;
        if(nc>k)return -1e9;
        if(i==n-1&&j==m-1)return grid[i][j];
        if(dp[i][j][nc]!=-1)return dp[i][j][nc];
        int r=dfs(i,j+1,nc,dp,grid,k);
        int d=dfs(i+1,j,nc,dp,grid,k);
        int best=grid[i][j]+max(r,d);
        return dp[i][j][nc]=best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+2,-1)));
        int res=dfs(0,0,0,dp,grid,k);
        if(res<0)return -1;
        return res;
    }
};