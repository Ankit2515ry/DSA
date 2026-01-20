class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=1;j<x;j++){
                if((j|(j+1))==x){
                    nums[i]=j;
                    break;
                }
            }
            if(x==nums[i])nums[i]=-1;
        }
        return nums;
    }
};