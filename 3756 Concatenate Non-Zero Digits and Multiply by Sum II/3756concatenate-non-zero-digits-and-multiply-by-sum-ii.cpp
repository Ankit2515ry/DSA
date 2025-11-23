class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>res;
        int n=s.size();
        int q=queries.size();
        long long mod=1e9+7;
        vector<long long >sum(n,0);
        vector<long long >nz(n,0);
        vector<int>c(n,0);
        vector<long long>p10(n+1,1);
        for(int i=1;i<=n;i++){
            p10[i]=(p10[i-1]*10)%mod;
        }
        for(int i=0;i<n;i++){
            int a=s[i]-'0';
            if(i>0){
                nz[i]=nz[i-1];
                sum[i]=sum[i-1];
                c[i]=c[i-1];
            }
            if(a!=0){
                nz[i]=(nz[i]*10+a)%mod;
                sum[i]=(sum[i]+a)%mod;
                c[i]++;
            }
        }
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long a=0;
            long long s=0;
            if(l==0){
                a=nz[r];
                s=sum[r];
            }else{
                int k=c[r]-c[l-1];
                a=(nz[r]-(nz[l-1]*p10[k])%mod+mod)%mod;
                s=(sum[r]-sum[l-1]+mod)%mod;
                
            }
            res.push_back((a*s)%mod);
        }
        return res;
    }
};