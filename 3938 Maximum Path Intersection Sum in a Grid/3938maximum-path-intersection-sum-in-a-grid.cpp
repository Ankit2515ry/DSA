class Solution {
public:
    int kadane(vector<int>& arr) {
        int n = arr.size();
        int cur = arr[0] + arr[1];
        int best = cur;
        for (int i = 2; i < n; i++) {
            cur = max(cur + arr[i],
                      arr[i - 1] + arr[i]);
            best = max(best, cur);
        }
        return best;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (m >= 2)
                res = max(res, kadane(grid[i]));
        }
        for (int j = 0; j < m; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            if (n >= 2)
                res = max(res, kadane(col));
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};