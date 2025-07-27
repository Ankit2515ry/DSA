class Solution {
public:
    long long numOfSubsequences(string s) {
        long long ansl=0;
        if(s.size()<2)return 0;
        long long n=s.size();
        vector<long long> v(n+1);
        long long t=0;
        for(long long i=n-1;i>=0;i--){
            if(s[i]=='T'){
                t++;
            } 
            v[i]=t;
        }
        long long l=1;
        for(long long i=0;i<n;i++){
            if(s[i]=='L')l++;
            else if(s[i]=='C'){
                ansl+=v[i]*l;
            }
        }
        long long lc=0;
        long long ansc=0;
        long long temp=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='L')lc++;
            else if(s[i]=='C'){
                ansc+=v[i]*lc;
            }
            temp=max(temp,v[i]*lc);
        }
        ansc+=temp;
        for(long long i=0;i<n;i++)v[i]+=1;
        long long lt=0;
        long long anst=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='L')lt++;
            else if(s[i]=='C'){
                anst+=v[i]*lt;
            }
        }
        return max(ansl,max(ansc,anst));
    }
};