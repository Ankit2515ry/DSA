class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s=to_string(n);
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int res=0;
        int pre=INT_MAX;
        for(auto it:mp){
            if(it.second<pre){
                pre=it.second;
                res=it.first-'0';
            }
        }
        return res;
    }
};