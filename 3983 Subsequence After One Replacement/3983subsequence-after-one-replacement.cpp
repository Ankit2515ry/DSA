class Solution {
public:
    // bool check(string &s,string &t) {
    //     int i=0,j=0;
    //     while(i<s.size()&&j<t.size()) {
    //         if(s[i]==t[j])
    //             i++;
    //         j++;
    //     }
    //     return i==s.size();
    // }
    bool canMakeSubsequence(string s, string t) {
        // if(s.size()>t.size())return false;
        // if(check(s,t))return true;
        // for(int i=0;i<s.size();i++){
        //     char ch=s[i];
        //     for(int j=0;j<26;j++){
        //         s[i]=char('a'+j);
        //         if(check(s,t))return true;
        //     }
        //     s[i]=ch;
        // }
        // return false;
        int n=s.size();
        int m=t.size();
        int j=0;
        for(int i=0;i<m;i++){
            if(t[i]==s[j])j++;
            if(j==n)return true;
        }
        if(j==n)return true;
        vector<int>l(n,-1);
        vector<int>r(n,-1);
        j=0;
        for(int i=0;i<n;i++){
            while(j<m&&s[i]!=t[j])j++;
            if(j==m)break;
            l[i]=j++;
        }
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0&&s[i]!=t[j])j--;
            if(j<0)break;
            r[i]=j--;
        }
        for(int i=0;i<n;i++){
            int x=(i==0)?-1:l[i-1];
            int y=(i==n-1)?m:r[i+1];
            if(x!=-1||i==0){
                if(y!=-1||i==n-1){
                    if(y-x>1)return true;
                }
            }
        }
        return false;
    }
};