class Solution {
public:
    long long dfs(int node,vector<vector<int>>& adj,vector<int>& baseTime){
        if(adj[node].empty())return baseTime[node];
        long long e=LLONG_MAX;
        long long l=LLONG_MIN;
        for(auto c:adj[node]){
            long long cft=dfs(c,adj,baseTime);
            e=min(e,cft);
            l=max(l,cft);
        }
        long long duration=(l-e)+baseTime[node];
        return l+duration;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        return dfs(0,adj,baseTime);
    }
};