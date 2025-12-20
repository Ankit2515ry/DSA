class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        multiset<int> ms;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            if (s[i] == '1') {
                auto it = prev(ms.end()); 
                ans += *it;
                ms.erase(it);
            }
        }
        return ans;
    }
};
