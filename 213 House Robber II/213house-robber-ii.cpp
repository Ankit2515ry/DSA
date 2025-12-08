class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        for(int i=n-2;i>=0;i--){
            c=max(b,nums[i]+a);
            a=b;
            b=c;
        }
        a=0;
        b=0;
        for(int i=n-1;i>0;i--){
            d=max(b,nums[i]+a);
            a=b;
            b=d;
        }
        return max(c,d);
    }
};