class Solution {
public:
    // int res=0;
    // void solve(int i,int amount, vector<int>& coins){
    //     int n=coins.size();
    //     if(i>=n||amount<=0){
    //         if(amount==0)res++;
    //         return ;
    //     }
    //     solve(i,amount-coins[i],coins);
    //     solve(i+1,amount,coins);  
    // }
    vector<vector<int>>dp;
    int solve(int i,int amount, vector<int>& coins){
        int n=coins.size();
        if(i>=n||amount<=0){
            if(amount==0)return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int a=solve(i,amount-coins[i],coins);
        int b=solve(i+1,amount,coins); 
        return dp[i][amount]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        // solve(0,amount,coins);
        // return res;
        int n=coins.size();
        //  vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        // for(int i=0;i<=n;i++)dp[i][0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=amount;j++){
        //         dp[i][j]=dp[i-1][j];
        //         if(j>=coins[i-1])dp[i][j]+=dp[i][j-coins[i-1]];
        //     }
        // }
        // return (int)dp[n][amount];
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};