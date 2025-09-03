class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int pre=image[sr][sc];
        if (pre == color) return image;
        vector<vector<int>>res=image;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=0;
        res[sr][sc]=color;
        vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+d[k].first;
                int y=j+d[k].second;
                if(x<n&&x>=0&&y<m&&y>=0&&image[x][y]==pre&&vis[x][y]==-1){
                    q.push({x,y});
                    vis[x][y]=0;
                    res[x][y]=color;
                }
            }
        }
        return res;
    }
};