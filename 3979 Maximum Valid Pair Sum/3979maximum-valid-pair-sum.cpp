class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n,0);
        vector<long long>suf(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],1LL*nums[i]);
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],1LL*nums[i]);
        }
        long long res=0;
        for(int i=0;i<n-k;i++){
            res=max(res,pre[i]+suf[i+k]);
        }
        return res;
    }
};