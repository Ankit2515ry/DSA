class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>mp;
        for(auto &it:nums)mp[it]++;
        for(auto &it:mp){
            if(it.second%k==0)res+=it.first*it.second;
        }
        return res;
    }
};