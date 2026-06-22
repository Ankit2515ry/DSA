class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)return true;
        // return false;
        vector<int>f(26,0);
        for(auto it:s){
            int idx=it-'a';
            f[idx]++;
        }
        for(auto it:t){
            int idx=it-'a';
            if(f[idx]==0)return false;
            f[idx]--;
        }
        bool fl=false;
        for(auto it:f)if(it>0)fl=true;
        if(fl)return false;
        return true;
    }
};