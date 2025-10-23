class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 0;
        int area = 1;
        vector<int> x = {1, 0, 0, -1};
        vector<int> y = {0, 1, -1, 0};
        for (int k = 0; k < 4; k++) {
            int xi = i + x[k];
            int yj = j + y[k];
            if (xi < grid.size() && xi >= 0 && yj < grid[0].size() && yj >= 0 &&
                grid[xi][yj] == 1 && vis[xi][yj] == -1) {
                area += dfs(xi, yj, grid, vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    int area = dfs(i, j, grid, vis);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};