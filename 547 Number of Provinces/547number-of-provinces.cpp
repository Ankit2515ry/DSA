class Solution {
public:
    int res=0;
    int n=0;
    void dfs(vector<vector<int>>& isConnected,int i,vector<int>& vis){
        vis[i]=0;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1&&vis[j]==-1){
                dfs(isConnected,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                res++;
                dfs(isConnected,i,vis);
            }
        }
        return res;
    }
};