class Solution {
public:
    int digitFrequencyScore(int n) {
        int res=0;
        unordered_map<int,int>mp;
        int x=n;
        while(x){
            int d=x%10;
            mp[d]++;
            x/=10;
        }
        for(auto it:mp){
            res+=it.first*it.second;
        }
        return res;
    }
};