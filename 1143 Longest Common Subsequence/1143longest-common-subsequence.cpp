class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string a,string b){
        int n=a.size();
        int m=b.size();
        if(i==n||j==m){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(i+1,j+1,a,b);
        }
        return dp[i][j]=max(solve(i+1,j,a,b),solve(i,j+1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // dp.assign(n,vector<int>(m,-1));
        // return solve(0,0,text1,text2);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(text1[i]==text2[j])dp[i][j]=1+dp[i+1][j+1];
        //         else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        // return dp[0][0];
        vector<int>dp(m+1,0);
        for(int i=n-1;i>=0;i--){
            int pre=0;//store dp[i+1][j+1] otherwise overwrite
            for(int j=m-1;j>=0;j--){
                int temp=dp[j];
                if(text1[i]==text2[j])dp[j]=1+pre;
                else dp[j]=max(dp[j],dp[j+1]);
                pre=temp;
            }
        }
        return dp[0];
    }
};