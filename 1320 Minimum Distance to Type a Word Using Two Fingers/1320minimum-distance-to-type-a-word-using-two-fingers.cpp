class Solution {
public:
    vector<pair<int,int>>idx;
    // vector<vector<vector<int>>>dp;
    // int solve(int i,int j,int k,string &word){
    //     int n=word.size();
    //     if(n==i)return 0;
    //     if(dp[i][j][k+1]!=-1)return dp[i][j][k+1];
    //     int l=idx[word[i]-'A'].first;
    //     int m=idx[word[i]-'A'].second;
    //     int a=idx[word[j]-'A'].first;
    //     int b=idx[word[j]-'A'].second;
    //     int x=l;
    //     int y=m;
    //     if(k!=-1){
    //         x=idx[word[k]-'A'].first;
    //         y=idx[word[k]-'A'].second;
    //     }
    //     int ans1=abs(l-a)+abs(m-b)+solve(i+1,i,k,word);
    //     int ans2=abs(l-x)+abs(m-y)+solve(i+1,j,i,word);
    //     return dp[i][j][k+1]=min(ans1,ans2);
    // }
    vector<vector<int>>dp;
    int solve(int i,int k,string &word){
        int n=word.size();
        if(n==i)return 0;
        if(dp[i][k+1]!=-1)return dp[i][k+1];
        int l=idx[word[i]-'A'].first;
        int m=idx[word[i]-'A'].second;
        int a=idx[word[i-1]-'A'].first;
        int b=idx[word[i-1]-'A'].second;
        int x=l;
        int y=m;
        if(k!=-1){
            x=idx[word[k]-'A'].first;
            y=idx[word[k]-'A'].second;
        }
        int ans1=abs(l-a)+abs(m-b)+solve(i+1,k,word);
        int ans2=abs(l-x)+abs(m-y)+solve(i+1,i-1,word);
        return dp[i][k+1]=min(ans1,ans2);
    }
    int minimumDistance(string word) {
        idx.resize(26);
        for(int i=0;i<26;i++){
            int a=i/6;
            int b=i%6;
            idx[i]={a,b};
        }
        // int n=word.size();
        // dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        // return solve(1,0,-1,word);
        //mle
        int n=word.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(1,-1,word);
    }
};