#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, vector<vector<int>>& adj, vector<int>& vis, int& count) {
        vis[idx] = 0;
        count++;
        for (int nei : adj[idx]) {
            if (vis[nei] == -1) {
                dfs(nei, adj, vis, count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2, dy = y1 - y2;
                if (dx * dx + dy * dy <= r1 * r1)
                    adj[i].push_back(j);
            }
        }
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, -1);
            int count = 0;
            dfs(i, adj, vis, count);
            res = max(res, count);
        }

        return res;
    }
};
