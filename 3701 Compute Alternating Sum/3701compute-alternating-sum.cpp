class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0)res+=nums[i];
            else res-=nums[i];
        }
        return res;
    }
};