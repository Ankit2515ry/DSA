#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> hwl(101);
        for (auto &r : rectangles)
            hwl[r[1]].push_back(r[0]);  
        for (int h = 1; h <= 100; h++)
            sort(hwl[h].begin(), hwl[h].end());
        vector<int> res;
        for (auto &p : points) {
            int x = p[0], y = p[1];
            int count = 0;
            for (int h = y; h <= 100; h++) {
                auto &v = hwl[h];
                if (v.empty()) continue;
                int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
                count += v.size() - idx;
            }
            res.push_back(count);
        }
        return res;
    }
};
