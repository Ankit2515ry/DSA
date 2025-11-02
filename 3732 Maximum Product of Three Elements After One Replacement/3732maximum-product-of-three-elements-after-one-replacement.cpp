class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int a=nums[n-1];
        int b=nums[n-2];
        long long res=1LL*a*b*100000;
        return res;
    }
};