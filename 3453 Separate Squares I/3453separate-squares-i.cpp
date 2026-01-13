class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;
        for (auto& s : squares) {
            double y = s[1], len = s[2];
            low = min(low, y);
            high = max(high, y + len);
        }
        auto areaDiff = [&](double k) {
            double below = 0.0;
            double total = 0.0;
            for (auto& s : squares) {
                double y = s[1], len = s[2];
                double area = len * len;
                total += area;
                if (k <= y) {
                    continue;
                } else if (k >= y + len) {
                    below += area;
                } else {
                    below += len * (k - y);
                }
            }
            return below - (total - below);
        };
        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            if (areaDiff(mid) < 0)
                low = mid;
            else
                high = mid;
        }
        return (low + high) / 2.0;
    }
};
