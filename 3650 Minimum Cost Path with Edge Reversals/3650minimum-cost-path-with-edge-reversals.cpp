class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            for (auto &p : adj[u]) {
                int v = p.first;
                long long w = p.second;      
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
