class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int c=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                c++;
                continue;
            }else{
                break;
            }
        }
        return n-c;
    }
};