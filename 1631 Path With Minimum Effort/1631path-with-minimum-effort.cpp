class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>x={1,0,-1,0};
        vector<int>y={0,1,0,-1};
        while(!pq.empty()){
            auto [e,p]=pq.top();
            auto [i,j]=p;
            pq.pop();
            cout<<e<<" "<<i<<" "<<j<<endl;
            if(i==n-1&&j==m-1)return e;
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&dist[ni][nj]>max(dist[i][j],abs(h[ni][nj]-h[i][j]))){
                    int ne=abs(h[ni][nj]-h[i][j]);
                    ne=max(ne,e);
                    dist[ni][nj] = ne;
                    pq.push({ne,{ni,nj}});
                }
            }
        }
        return 0;
    }
};