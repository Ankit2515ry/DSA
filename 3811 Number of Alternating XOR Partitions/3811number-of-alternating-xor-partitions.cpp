class Solution {
public:
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        int n=nums.size();
        long long res=0;
        long long mod=1e9+7;
        unordered_map<long long,long long>mp1,mp2;
        mp2[0]=1;
        long long x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            long long a=mp2[t1^x];
            long long b=mp1[t2^x];
            mp1[x]=(mp1[x]+a)%mod;
            mp2[x]=(mp2[x]+b)%mod;
            res=(a+b)%mod;
        }
        return (int)res;
    }
};