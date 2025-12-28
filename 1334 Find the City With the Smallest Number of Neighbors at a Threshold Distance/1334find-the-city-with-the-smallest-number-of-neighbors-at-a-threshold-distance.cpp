class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int inf=1e9;
        vector<vector<int>>dis(n,vector<int>(n,inf));
        for(int i=0;i<n;i++)dis[i][i]=0;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dis[u][v]=min(dis[u][v],w);
            dis[v][u]=min(dis[v][u],w);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        int city=-1;
        int smallnum=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j&&dis[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=smallnum){
                if(count==smallnum){
                    city=i;
                }else{
                    city=i;
                    smallnum=count;
                }
            }
        }
        return city;
    }
};