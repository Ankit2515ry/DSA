class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        vector<int>bit(32,-1);
        for(int i=n-1;i>=0;i--){
            int idx=i;
            for(int j=0;j<32;j++){
                if(nums[i]&1<<j)bit[j]=i;
            }
            for(int j=0;j<32;j++){
                idx=max(idx,bit[j]);
            }
            res[i]=idx-i+1;
        }
        return res;
    }
};