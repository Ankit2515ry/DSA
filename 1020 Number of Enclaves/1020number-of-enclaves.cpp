class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        //cout<<i<<" "<<j<<endl;
        vis[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++){
            int x=i+d[k].first;
            int y=j+d[k].second;
            if(x<n&&x>=0&&y<m&&y>=0&&grid[x][y]==1&&vis[x][y]==-1){
                dfs(grid,vis,x,y);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)vis[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]&&vis[0][i]==-1)dfs(grid,vis,0,i);
            if(grid[n-1][i]&&vis[n-1][i]==-1)dfs(grid,vis,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]&&vis[i][0]==-1)dfs(grid,vis,i,0);
            if(grid[i][m-1]&&vis[i][m-1]==-1)dfs(grid,vis,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1)res++;
            }
        }
        return res;
    }
};