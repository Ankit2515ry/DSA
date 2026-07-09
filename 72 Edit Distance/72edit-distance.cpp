class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(int i,int j,string &a,string &b){
    //     int n=a.size();
    //     int m=b.size();
    //     if(i==n)return m-j; 
    //     if(j==m)return n-i;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(a[i]==b[j])return dp[i][j]=solve(i+1,j+1,a,b);
    //     int x=solve(i,j+1,a,b)+1;
    //     int y=solve(i+1,j,a,b)+1;
    //     int z=solve(i+1,j+1,a,b)+1;
    //     return dp[i][j]=min({x,y,z});
    // }
    int n=0;
    int m=0;
    vector<vector<int>>dp;
    int solve(string &a,string &b,int i,int j){
        if(i==n)return m-j; 
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]=solve(a,b,i+1,j+1);
        int x=solve(a,b,i,j+1)+1;
        int y=solve(a,b,i+1,j)+1;
        int z=solve(a,b,i+1,j+1)+1;
        return dp[i][j]=min({x,y,z});
    }
    int minDistance(string word1, string word2) {
        // int n=word1.size();
        // int m=word2.size();
        // dp.assign(n,vector<int>(m,-1));
        // return solve(0,0,word1,word2);
        n=word1.size();
        m=word2.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(word1,word2,0,0);
    }
};