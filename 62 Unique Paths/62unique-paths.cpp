class Solution {
public:
    // int mm=0;
    // int nn=0;
    // int solve(int i,int j){
    //     if(i==mm&&j==nn)return 1;
    //     if(i>mm||j>nn)return 0;
    //     int a=solve(i+1,j);
    //     int b=solve(i,j+1);
    //     return a+b;
    // }

    // vector<vector<int>>dp;
    // int mm=0;
    // int nn=0;
    // int solve(int i,int j){
    //     if(i==mm&&j==nn)return 1;
    //     if(i>mm||j>nn)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int a=solve(i+1,j);
    //     int b=solve(i,j+1);
    //     return dp[i][j]=a+b;
    // }
    int uniquePaths(int m, int n) {
        // O(pow(2,m+n)) time complexity and O(m+n) space complexity recursion stack
        // mm=m-1;
        // nn=n-1;
        // return solve(0,0);
        
        //O(m*n) time and space complexity
        // mm=m-1;
        // nn=n-1;
        // dp.assign(m,vector<int>(n,-1));
        // return solve(0,0);

        //O(m*n) time and space complexity
        // vector<vector<int>>dp(m,vector<int>(n,1));
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];

        //O(m*n) time and O(n) space complexity
        // vector<int>dp(n,1);
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[j]+=dp[j-1];
        //     }
        // }
        // return dp[n-1];

        int nc=m+n-2;
        long long res=1;
        int r=min(n-1,m-1);
        nc-=r;
        for(int i=1;i<=r;i++){
            res=res*(nc+i)/i;
        }
        return (int)res;
    }
};