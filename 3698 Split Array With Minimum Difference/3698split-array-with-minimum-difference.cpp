class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n), suf(n);
        vector<bool> p(n), s(n);
        pre[0] = nums[0];
        p[0] = true;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
            if (p[i-1] && nums[i-1] < nums[i]) p[i] = true;
            else p[i] = false;
        }
        suf[n-1] = nums[n-1];
        s[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] + nums[i];
            if (s[i+1] && nums[i] > nums[i+1]) s[i] = true;
            else s[i] = false;
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            if (p[i] && s[i+1]) {
                res = min(res, abs(pre[i] - suf[i+1]));
            }
        }

        return (res == LLONG_MAX ? -1 : res);
    }
};
