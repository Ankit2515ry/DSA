class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int p=0;
        int r=0;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            p+=it.second/2;
            r+=it.second%2;
        }
        return {p,r};
    }
};