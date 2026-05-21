class Solution {
public:
    int mod=1e9+7;
    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        // int n=nums.size();
        // int m=q.size();
        // int mod=1e9+7;
        // for(auto it:q){
        //     int l=it[0];
        //     int r=it[1];
        //     int k=it[2];
        //     int v=it[3];
        //     int idx=l;
        //     while(idx<=r){
        //         long long temp=1LL*nums[idx]*v;
        //         temp%=mod;
        //         nums[idx]=temp;
        //         idx+=k;
        //     }
        // }
        // int res=nums[0];
        // for(int i=1;i<n;i++){
        //     res^=nums[i];
        // }
        // return res;
        int n=nums.size();
        int m=q.size();
        vector<int>pre(n+sqrt(n)+1,0);
        map<int,vector<vector<int>>>mp;
        for(auto it:q){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            if(k>sqrt(n)){
                    int idx=l;
                while(idx<=r){
                    long long temp=1LL*nums[idx]*v;
                    temp%=mod;
                    nums[idx]=temp;
                    idx+=k;
                }
            }else{
                mp[k].push_back(it);
            }
        }
        for(auto it:mp){
            int k=it.first;
            vector<long long>diff(n+k,1);
            auto temp=it.second;
            for(auto i:temp){
                int l=i[0];
                int r=i[1];
                int v=i[3];
                diff[l]=diff[l]*v%mod;
                int rr = ((r - l) / k + 1) * k + l;
                diff[rr]=diff[rr]*modpow(v,mod-2)%mod;
            }
            for (int i = k; i < n; i++) {
                diff[i] = diff[i] * diff[i - k] % mod;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * diff[i] % mod;
            }
        }
        int res=nums[0];
        for(int i=1;i<n;i++){
            res^=nums[i];
        }
        return res;
        
    }
};