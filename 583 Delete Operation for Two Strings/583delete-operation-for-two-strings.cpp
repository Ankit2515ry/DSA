class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string a,string b){
        int n=a.size();
        int m=b.size();
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]=solve(i+1,j+1,a,b)+1;
        int x=solve(i+1,j,a,b);
        int y=solve(i,j+1,a,b);
        return dp[i][j]=max(x,y);
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n,vector<int>(m,-1));
        int res= solve(0,0,word1,word2);
        int temp=word1.size()+word2.size();
        res=temp-(2*res);
        return res;
    }
};