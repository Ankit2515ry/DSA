class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[x] > rank[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;
        DSU dsu(n + 2);

        vector<vector<int>> grid(row, vector<int>(col, 1));

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        auto id = [&](int r, int c) {
            return r * col + c;
        };

        for (int day = cells.size() - 1; day >= 0; day--) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 0;

            int curr = id(r, c);

            if (r == 0) dsu.unite(curr, TOP);
            if (r == row - 1) dsu.unite(curr, BOTTOM);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < row && nc < col && grid[nr][nc] == 0) {
                    dsu.unite(curr, id(nr, nc));
                }
            }

            if (dsu.find(TOP) == dsu.find(BOTTOM))
                return day;
        }

        return 0;
    }
};
