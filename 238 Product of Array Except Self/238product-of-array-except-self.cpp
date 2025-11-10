class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>res(n,0);
        // int f=0;
        // int mul=1;
        // for(auto &it:nums){
        //     if(it==0)f++;
        //     else mul*=it;
        // }
        // if(f>1)return res;
        // for(int i=0;i<n;i++){
        //     if(f==1&&nums[i]==0){
        //         res[i]=mul;
        //     }else if(f==0){
        //         res[i]=mul/nums[i];
        //     }
        // }
        // return res;
        int n=nums.size();
        vector<int>res(n,0);
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int mul=1;
        int mul1=1;
        for(int i=0;i<n;i++){
            mul*=nums[i];
            mul1*=nums[n-i-1];
            pre[i]=mul;
            suf[n-i-1]=mul1;
        }
        for(int i=0;i<n;i++){
            if(i==0)res[i]=suf[i+1];
            else if(i==n-1)res[i]=pre[i-1];
            else res[i]=pre[i-1]*suf[i+1];
        }
        return res;
    }
};