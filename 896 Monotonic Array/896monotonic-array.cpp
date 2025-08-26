class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        bool f=true;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])f=false;
        }
        if(f)return true;
        if(!f){
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1])return false;
            }
        }
        return true;
    }
};