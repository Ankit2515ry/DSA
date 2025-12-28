class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;

        if (rankv[px] < rankv[py]) {
            parent[px] = py;
        } else if (rankv[px] > rankv[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rankv[px]++;
        }
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || 
                    stones[i][1] == stones[j][1]) {
                    dsu.unite(i, j);
                }
            }
        }
        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(dsu.find(i));
        }
        return n - components.size();
    }
};
