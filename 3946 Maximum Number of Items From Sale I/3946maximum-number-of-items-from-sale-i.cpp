class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>free(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0)free[i]++;
            }
        }
        vector<int>dp(budget+1,0);
        for(int i=0;i<n;i++){
            int c=items[i][1];
            for(int j=budget;j>=c;j--){
                dp[j]=max(dp[j],dp[j-c]+1+free[i]);
            }
            for(int j=c;j<=budget;j++){
                dp[j]=max(dp[j],dp[j-c]+1);
            }
        }
        int res=0;
        for(auto it:dp)res=max(res,it);
        return res;
    }
};