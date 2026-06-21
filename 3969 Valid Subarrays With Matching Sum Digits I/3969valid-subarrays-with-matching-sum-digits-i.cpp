class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long>pre;
        pre.push_back(0);
        for(auto it:nums)pre.push_back(it);
        int n=nums.size();
        for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long sum=pre[j]-pre[i-1];
                // string s=to_string(sum);
                // int m=s.size();
                // if((int)(s[0]-'0')==x&&(int)(s[m-1]-'0')==x)res++;
                if(sum%10==x){
                    while(sum>=10)sum/=10;
                    if(sum==x)res++;
                }
            }
        }
        return res;
    }
};