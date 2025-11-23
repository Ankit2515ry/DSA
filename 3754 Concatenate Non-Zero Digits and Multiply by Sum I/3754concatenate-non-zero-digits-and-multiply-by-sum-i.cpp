class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string a="";
        long long sum=0;
        for(auto &it:s){
            if(it!='0')a+=it;
            sum+=it-'0';
        }
        long long x=0;
        if(!a.empty())x=stoll(a);
        long long res=x*sum;
        return res;       
    }
};