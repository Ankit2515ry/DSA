class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        long long maxele=0;
        long long x=nums[0];
        int j=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            maxele=nums[i];
            if(maxele>x*k){
                while(maxele>x*k){
                    j++;
                    x=nums[j];
                }
            }
            else res=max(res,i-j+1);
            cout<<res<<" ";
        }
        return n-res;
    }
};