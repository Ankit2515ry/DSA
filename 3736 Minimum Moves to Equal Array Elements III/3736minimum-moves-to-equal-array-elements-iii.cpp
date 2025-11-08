class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>m)m=nums[i];
        }
        int res=0;
        for(auto &it:nums){
            res+=m-it;
        }
        return res;
    }
};