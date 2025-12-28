class Solution {
public:
    vector<vector<int>>res;
    vector<int>vis;
    void dfs(int ind,vector<int>&temp,vector<vector<int>>& graph){
        int n=graph.size();
        if(ind==n-1){
            temp.push_back(ind);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        vis[ind]=0;
        temp.push_back(ind);
        for(auto &it:graph[ind]){
            if(vis[it]==-1)dfs(it,temp,graph);
        }
        temp.pop_back();
        vis[ind]=-1;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        int n=graph.size();
        vis.assign(n,-1);
        //temp.push_back(0);
        dfs(0,temp,graph);
        return res;
    }
};