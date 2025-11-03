class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;
        map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        while(!mp.empty()){
            int a=mp.begin()->first;
            int b=mp.begin()->second;
            for(int i=0;i<k;i++){
                if(mp.find(a)==mp.end()||mp[a]<b)return false;
                mp[a]-=b;
                if(mp[a]==0)mp.erase(a);
                a++;
            }
        }
        return true;
    }
};