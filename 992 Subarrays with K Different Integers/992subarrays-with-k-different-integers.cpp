class Solution {
public:
    long long solve(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        long long res=0;
        int j=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.size()<=k){
                res+=i-j+1;
            }
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0)mp.erase(nums[j]);
                    j++;
                }
                res+=i-j+1;
            }
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res=solve(nums,k)-solve(nums,k-1);
        return res;
    }
};