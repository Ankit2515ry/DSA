class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int temp = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            temp = ((temp << 1) + nums[i]) % 5;
            if(temp==0)res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};