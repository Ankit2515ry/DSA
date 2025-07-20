class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        long long size = grid[i][j];
        for (auto [dx, dy] : dirs) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                grid[ni][nj] >0 && vis[ni][nj] == -1) {
                size += dfs(ni, nj, grid, vis);
            }
        }
        return size;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && vis[i][j] == -1) {
                    long long size = dfs(i, j, grid, vis);
                    if (size%k==0) ans++;
                }
            }
        }
        return ans;
    }
};
