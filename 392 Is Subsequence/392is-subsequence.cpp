class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size()+1;
        int n=t.size()+1;
        vector<vector<int>>a(m,vector<int>(n,0));
        int i=1;
        int j=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(s[i-1]==t[j-1]){
                    a[i][j]=1+a[i-1][j-1];
                }
                else{
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
                }
            }
        }
        if(s.size()==a[m-1][n-1])return true;
        return false;
    }
};