#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int perimeter = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        int n = grid.size(), m = grid[0].size();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == 0)
                perimeter++;
            else if (vis[ni][nj] == -1)
                dfs(ni, nj, grid, vis);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, vis);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};
