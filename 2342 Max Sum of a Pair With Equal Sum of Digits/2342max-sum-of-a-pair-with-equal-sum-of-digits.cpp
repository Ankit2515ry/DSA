class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(auto it:nums){
            int sum=0;
            string s=to_string(it);
            for(auto i:s){
                sum+=(i-'0');
            }
            mp[sum].push_back(it);
        }
        int res=-1;
        for(auto it:mp){
            if(it.second.size()>1){
                auto a=it.second;
                sort(a.begin(),a.end());
                int m=a.size();
                res=max(res,a[m-1]+a[m-2]);
            }
        }
        return res;
    }
};