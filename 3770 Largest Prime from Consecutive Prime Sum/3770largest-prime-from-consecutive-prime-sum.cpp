class Solution {
public:
    bool solve(int n){
        if(n==1||n==0)return false;
        if(n==2||n==3)return true;
        if(n%2==0||n%3==0)return false;
        for(long long i=5;i*i<=1LL*n;i+=6){
            if(n%i==0||n%(i+2)==0)return false;
        }
        return true;
    }
    int largestPrime(int n) {
        int res=0;
        vector<bool>sei(n+1,true);
        sei[0]=sei[1]=false;
        for(int i=2;i<=n;i++){
            if(sei[i]){
                long long st=1LL*i*i;
                if(st>n)continue;
                for(long long j=st;j<=n;j+=i){
                    sei[j]=false;
                }
            }
        }
        vector<int>pri;
        for(int i=2;i<=n;i++){
            if(sei[i])pri.push_back(i);
        }
        long long sum=0;
        for(long long i=0;i<pri.size();i++){
            sum+=pri[i];
            if(sum<=n&&solve(sum)){
                res=sum;
            }
        }
        return res;
    }
};