class Solution {
public:
    bool check(long long n,long long r){
        return (n>=-r&&n<=r);
    }
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int>res(n);
        long long sum=1LL*n*(n+1)/2;
        for(int i=0;i<n;i++){
            int v=n-i;
            long long nt=target+v;
            if(check(nt,sum-v)){
                res[i]=-v;
                target=nt;
                sum-=v;
                continue;
            }
            nt=target-v;
            if(check(nt,sum-v)){
                res[i]=v;
                target=nt;
                sum-=v;
                continue;
            }
            return {};
        }
        if(target!=0)return {};
        sort(res.begin(),res.end());
        return res;
    }
};