class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>vis(n,-1);
        // long long res=0;
        // sort(nums.begin(),nums.end());
        // int m=nums[n-1];
        // unordered_map<int,vector<int>>mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]].push_back(i);
        // }
        // for(int i=0;i<n;i++){
        //     if(vis[i]==-1){
        //         vis[i]=0;
        //         int val=nums[i];
        //         res+=val;
        //         for(int j=val;j<=m;j+=val){
        //             if(mp.count(j)&&vis[mp[j][0]]==-1){
        //                 auto a=mp[j];
        //                 for(auto it:a){
        //                     vis[it]=0;
        //                     res+=val;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return res;
        int n=nums.size();
        int m=1e5;
        vector<bool>temp(m,false);
        for(auto it:nums)temp[it]=true;
        long long res=0;
        for(auto it:nums){
            int best=it;
            for(int i=1;1LL*i*i<=it;i++){
                if(it%i==0){
                    if(temp[i]){
                        best=i;
                        break;
                    }
                    int alt=it/i;
                    if(temp[alt]){
                        best=min(best,alt);
                    }
                }
            }
            res+=best;
        }
        return res;
    }
};