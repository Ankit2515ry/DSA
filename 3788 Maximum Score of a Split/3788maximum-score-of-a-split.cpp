class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long >pre;
        long long temp=0;
        for(auto &it:nums){
            temp+=it;
            pre.push_back(temp);
        }
        int n=nums.size();
        vector<int >suf(n,0);
        int temp1=INT_MAX;
        for(int i=n-1;i>=0;i--){
            temp1=min(temp1,nums[i]);
            suf[i]=temp1;
        }
        long long res=LLONG_MIN;
        for(int i=0;i<n-1;i++){
            res=max(res,pre[i]-1LL*suf[i+1]);
        }
        return res;
    }
};