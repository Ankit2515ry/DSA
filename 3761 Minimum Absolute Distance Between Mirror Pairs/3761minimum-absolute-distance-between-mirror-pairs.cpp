class Solution {
public:
    int rev(int n){
        int a=0;
        while(n>0){
            a=a*10+(n%10);
            n/=10;
        }
        return a;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            int r=rev(nums[i]);
            if(mp.find(r)==mp.end())continue;
            const vector<int>&temp=mp[r];
            auto it=upper_bound(temp.begin(),temp.end(),i);
            if(it!=temp.end()){
                res=min(res,*it-i);
            }
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};