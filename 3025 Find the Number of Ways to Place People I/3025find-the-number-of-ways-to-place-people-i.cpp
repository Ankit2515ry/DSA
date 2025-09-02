class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int Ax = points[i][0], Ay = points[i][1];
                int Bx = points[j][0], By = points[j][1];
                if (Ax <= Bx && Ay >= By) {
                    bool ok = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int Cx = points[k][0], Cy = points[k][1];
                        if (Ax <= Cx && Cx <= Bx && By <= Cy && Cy <= Ay) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) res++;
                }
            }
        }
        return res;
    }
};
