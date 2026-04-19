class Solution {
public:
    vector<int> getPath(string &dir) {
        vector<int> path;
        int r = 0, c = 0;
        path.push_back(0); 
        for (char d : dir) {
            if (d == 'D') r++;
            else c++;
            path.push_back(r * 4 + c);
        }
        return path;
    }
    long long dfs(int pos, int step, int last, bool tight, string &num,
                  vector<int> &path,
                  vector<vector<vector<vector<long long>>>> &dp) {

        if (pos == 16) return 1;
        if (dp[pos][step][last][tight] != -1)
            return dp[pos][step][last][tight];
        int limit = tight ? (num[pos] - '0') : 9;
        long long res = 0;
        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);
            if (step < 7 && pos == path[step]) {
                if (step == 0) {
                    res += dfs(pos + 1, step + 1, d, ntight, num, path, dp);
                } 
                else if (d >= last) {
                    res += dfs(pos + 1, step + 1, d, ntight, num, path, dp);
                }
            } else {
                res += dfs(pos + 1, step, last, ntight, num, path, dp);
            }
        }
        return dp[pos][step][last][tight] = res;
    }

    long long solve(string num, vector<int> &path) {
        using ll = long long;
        vector<vector<vector<vector<ll>>>> dp(17,
            vector<vector<vector<ll>>>(8,
                vector<vector<ll>>(11,
                    vector<ll>(2, -1))));
        return dfs(0, 0, 0, 1, num, path, dp);
    }

    string pad(long long x) {
        string s = to_string(x);
        while (s.size() < 16) s = "0" + s;
        return s;
    }

    long long countUpTo(long long x, vector<int> &path) {
        if (x < 0) return 0;
        return solve(pad(x), path);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        vector<int> path = getPath(directions);
        return countUpTo(r, path) - countUpTo(l - 1, path);
    }
};