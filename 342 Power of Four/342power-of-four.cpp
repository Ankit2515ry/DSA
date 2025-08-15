class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        long long a=1;
        while(a<=n){
            if(a==n)return true;
            a*=4;
        }
        return false;
    }
};