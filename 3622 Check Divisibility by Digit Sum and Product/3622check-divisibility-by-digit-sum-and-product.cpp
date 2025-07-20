class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int k=n;
        while(n){
            int temp=n%10;
            sum+=temp;
            pro*=temp;
            n/=10;
        }
        int f_sum=sum+pro;
        cout<<f_sum;
        if(k%f_sum==0)return true;
        return false;
    }
};