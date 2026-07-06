class Solution {
public:
    long long mod=1e9+7;
    vector<vector<vector<long long>>>dp;
    long long solve(string &a,string &b,string &t,int i,int j,int k){
        if(k==t.size())return (i&&j);
        if(i==a.size()&&j==b.size())return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long res=0;
        for(int x=i;x<a.size();x++){
            if(a[x]==t[k])res=(res+solve(a,b,t,x+1,j,k+1))%mod;
        }
        for(int x=j;x<b.size();x++){
            if(b[x]==t[k])res=(res+solve(a,b,t,i,x+1,k+1))%mod;
        }
        return dp[i][j][k]=res;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        dp.assign(
            word1.size() + 1,
            vector<vector<long long>>(
                word2.size() + 1,
                vector<long long>(target.size() + 1, -1)
            )
        );
        long long res=solve(word1,word2,target,0,0,0);
        return res;
    }
};