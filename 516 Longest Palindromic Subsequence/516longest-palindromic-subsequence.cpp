class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size()+1;
        string a=s;
        reverse(a.begin(),a.end());
        vector<int>dp(m,0);
        for(int i=m-2;i>=0;i--){
            int pre=0;
            for(int j=m-2;j>=0;j--){
                int temp=dp[j];
                if(s[i]==a[j])dp[j]=1+pre;
                else{
                    dp[j]=max(dp[j],dp[j+1]);
                }
                pre=temp;
            }
        }
        return dp[0];
        // vector<vector<int>>dp(m,vector<int>(m,0));
        // string t=s;
        // reverse(s.begin(),s.end());
        // int i=1;
        // int j=1;
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<m;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[m-1][m-1];
    }
};