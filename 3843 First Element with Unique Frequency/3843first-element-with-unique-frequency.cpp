class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp,mpp;
        for(auto &it:nums)mp[it]++;
        for(auto &it:mp)mpp[it.second]++;
        for(int i=0;i<nums.size();i++){
            if(mpp[mp[nums[i]]]==1)return nums[i];
        }
        return -1;
    }
};