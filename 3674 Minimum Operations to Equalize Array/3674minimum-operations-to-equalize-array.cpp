class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        int pre=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=pre)f=true;
        }
        if(f)return 1;
        return 0;
    }
};