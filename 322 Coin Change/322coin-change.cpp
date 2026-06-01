class Solution {
public:
    int n=0;
    vector<int>dp;
    int solve(vector<int>& coins, int amount){
        if(amount<0)return -1;
        if(amount==0)return 0;
        if(dp[amount]!=INT_MAX)return dp[amount];
        int res=INT_MAX;
        for(auto it:coins){
            int temp=solve(coins,amount-it);
            if(temp>=0&&temp<res){
                res=1+temp;
            }
        }
        return dp[amount]=(res==INT_MAX)?-1:res;
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.assign(amount+1,INT_MAX);
        int res=solve(coins,amount);
        return res;

    }
};