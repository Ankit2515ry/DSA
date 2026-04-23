class Solution {
public:
    //vector<vector<long long>>dp;
    // long long solve(int i,int j,vector<vector<int>>& points){
    //     if(i==points.size())return 0;
    //     if(dp[i][j]!=-1e11)return dp[i][j];
    //     long long res=0;
    //     for(int k=0;k<points[0].size();k++){
    //         res=max(res,points[i][k]-abs(j-k)+solve(i+1,k,points));
    //     }
    //     return dp[i][j]=res;
    // }
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        // long long res=0;
        // dp.assign(n,vector<long long>(m,-1e11));
        // for(int i=0;i<m;i++){
        //     res=max(res,solve(0,i,points));
        // }
        // return res;
        vector<long long>p(m,0);
        for(int i=0;i<m;i++){
            p[i]=points[0][i];
        }
        for(int i=1;i<n;i++){
            vector<long long>l(m,0);
            vector<long long>r(m,0);
            vector<long long>c(m,0);
            l[0]=p[0];
            for(int j=1;j<m;j++){
                l[j]=max(l[j-1]-1,p[j]);
            }
            r[m-1]=p[m-1];
            for(int j=m-2;j>=0;j--){
                r[j]=max(r[j+1]-1,p[j]);
            }
            for(int j=0;j<m;j++){
                c[j]=points[i][j]+max(l[j],r[j]);
            }
            p=c;
        }
        long long res=0;
        for(int i=0;i<m;i++){
            res=max(res,p[i]);
        }
        return res;

    }
};