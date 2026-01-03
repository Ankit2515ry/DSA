class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9+7;
        long long a = 6, b = 6;
        for (int i = 2; i <= n; i++) {
            long long newA=(2 * a + 2 * b) % MOD;
            long long newb=(2 * a + 3 * b) % MOD;
            a = newA;
            b = newb;
        }
        return (a + b) % MOD;
    }
};