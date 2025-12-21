class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        long long maxi=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=cost[i];
            maxi+=cost[i];
        }
        
        long long m=0;
        for(auto &it:mp){
            long long a=it.second;
            m=max(m,a);
        }
        return (maxi-m);
    }
};