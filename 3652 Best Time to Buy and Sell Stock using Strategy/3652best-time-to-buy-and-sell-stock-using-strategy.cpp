class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> priSum(n+1, 0);
        vector<long long> pms(n+1, 0);
        long long res = 0;
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            res += 1LL * prices[i] * strategy[i];
            priSum[i+1] = priSum[i] + prices[i];
            pms[i+1] = pms[i] + 1LL * prices[i] * strategy[i];
        }
        for (int i = 0; i + k <= n; i++) {
            long long pre = pms[i+k] - pms[i];
            long long ne = priSum[i+k] - priSum[i+k/2];
            long long x = ne - pre;
            temp = max(temp, x);
        }
        return res + temp;
    }
};
