class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it:mp){
            if(it.second.size()>2){
                for(int i=0;i<it.second.size()-2;i++){
                    int temp=abs(it.second[i+1]-it.second[i])+abs(it.second[i+2]-it.second[i])+abs(it.second[i+2]-it.second[i+1]);
                    res=min(res,temp);
                }
            }
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};