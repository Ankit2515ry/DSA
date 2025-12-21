class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)return -1;
        if(n==1&&grid[0].size()==1)return 1;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        vector<int>x={0,0,1,1,1,-1,-1,-1};
        vector<int>y={1,-1,0,1,-1,0,1,-1};
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=0;
        int res=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                for(int k=0;k<8;k++){
                    int xx=i+x[k];
                    int yy=j+y[k];
                    if(xx>=0&&xx<n&&yy>=0&&yy<n&&grid[xx][yy]==0&&vis[xx][yy]!=0){
                        if(xx==n-1&&yy==n-1){
                            res++;
                            return res;
                        }
                        vis[xx][yy]=0;
                        q.push({xx,yy});
                    }
                }
            }
            res++;
        }
        return -1;
    }
};