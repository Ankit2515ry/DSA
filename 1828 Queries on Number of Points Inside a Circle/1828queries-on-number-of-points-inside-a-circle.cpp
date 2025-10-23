class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), q = queries.size();
        vector<int> ans(q, 0);
        for (int j = 0; j < q; j++) {
            int cx = queries[j][0];
            int cy = queries[j][1];
            int r  = queries[j][2];
            int r2 = r * r;
            for (int i = 0; i < n; i++) {
                int dx = points[i][0] - cx;
                int dy = points[i][1] - cy;
                if (dx * dx + dy * dy <= r2)
                    ans[j]++;
            }
        }
        return ans;
    }
};
