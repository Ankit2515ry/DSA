class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)q.push({i,j});
            }
        }
        int md=1;
        vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int si=q.size();
            while(si--){
                auto[i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x=i+d[k].first;
                    int y=j+d[k].second;
                    if(x<n&&x>=0&&y<m&&y>=0&&mat[x][y]==1){
                        q.push({x,y});
                        res[x][y]=md;
                        mat[x][y]=0;
                    }
                }
            }
            md++;
        }
        return res;
    }
};