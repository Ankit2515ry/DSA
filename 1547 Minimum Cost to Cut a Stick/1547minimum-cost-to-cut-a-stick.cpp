class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& cuts){
        if(j-i<=1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int n=cuts.size();
        int mi=INT_MAX;
        for(int k=i+1;k<j;k++){
            int temp=solve(i,k,cuts)+solve(k,j,cuts)+(cuts[j]-cuts[i]);
            mi=min(mi,temp);
        }
        return dp[i][j]=mi;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        dp.assign(m,vector<int>(m,-1));
        return solve(0,m-1,cuts);
    }
};
// class Solution {
// public:
//     int solve(int i,int j,vector<int>& cuts){
//         if(j-i==1)return 0;
//         int n=cuts.size();
//         int mi=INT_MAX;
//         for(int k=0;k<n;k++){
//             int x=cuts[k];
//             if(i<x&&x<j){
//                 int temp=solve(i,x,cuts)+solve(x,j,cuts)+(j-i);
//                 mi=min(mi,temp);
//             }
//         }
//         if(mi==INT_MAX)return 0;
//         return mi;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         sort(cuts.begin(),cuts.end());
//         return solve(0,n,cuts);
//     }
// };