class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        int res=0;
        int px=0;
        int p=0;
        unordered_map<int,unordered_map<int,int>>mp;
        mp[0][0]=-1;
        for(int i=0;i<n;i++){
            px^=nums[i];
            p+=(nums[i]%2==0?1:-1);
            if(mp[px].find(p)!=mp[px].end()){
                res=max(res,i-mp[px][p]);
            }
            else{
                mp[px][p]=i;
            }
        }
        return res;
    }
};