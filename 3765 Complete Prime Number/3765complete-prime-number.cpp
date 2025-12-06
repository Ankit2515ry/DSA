class Solution {
public:
    bool check(int n){
        if(n<=1)return false;
        else{
            for(long long i=2;i*i<=n;i++){
                if(n%i==0)return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        bool f=true;
        string s=to_string(num);
        int n=s.size();
        string a="";
        for(int i=0;i<n;i++){
            a+=s[i];
            int x=stoi(a);
            f=check(x);
            if(f==false)return f;
        }
        a="";
        for(int i=n-1;i>=0;i--){
            a+=s[i];
            reverse(a.begin(),a.end());
            int x=stoi(a);
            f=check(x);
            reverse(a.begin(),a.end());
            if(f==false)return f;
        }
        return f;
    }
};