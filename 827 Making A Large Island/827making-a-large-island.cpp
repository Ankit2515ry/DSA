class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int id1 = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int id2 = ni * n + nj;
                            dsu.unite(id1, id2);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> comps;
                    int curr = 1; 
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int root = dsu.find(ni * n + nj);
                            if (!comps.count(root)) {
                                curr += dsu.size[root];
                                comps.insert(root);
                            }
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        if (ans == 0) return n * n;
        return ans;
    }
};
