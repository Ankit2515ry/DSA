class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        int mod = 1e9+7;
        for (int i = 0; i < m; i++) {
            int li = q[i][0];
            int ri = q[i][1];
            int ki = q[i][2];
            int vi = q[i][3];
            int idx = li;
            while (idx <= ri) {
                long long a = (1LL * nums[idx] * vi) % mod; 
                nums[idx] = (int)a;
                idx += ki;
            }
        }
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            res ^= nums[i];
        }
        return res;
    }
};
