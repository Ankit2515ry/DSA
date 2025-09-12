class Solution {
public:
    bool doesAliceWin(string s) {
        int vo=0;
        int n=s.size();
        for(int i=0;i<n;i++)if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')vo++;
        if(vo>0)return true;
        return false;
    }
};