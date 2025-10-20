class Solution {
public:
    int longestBalanced(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            vector<int>mp(26,0);
            for(int j=i;j<s.size();j++){
                mp[s[j]-'a']++;
                bool f=true;
                int a=0;
                for(int k=0;k<26;k++){
                    if(mp[k]!=0){
                        a=mp[k];
                        break;
                    }
                }
                for(int k=0;k<26;k++){
                    if(mp[k]!=0&&mp[k]!=a)f=false;
                }
                if(f)res=max(res,j-i+1);
            }
        }
        return res;
    }
};