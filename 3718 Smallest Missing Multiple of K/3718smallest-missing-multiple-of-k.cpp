class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=k;
        int x=k;
        unordered_set<int>st;
        for(auto &it:nums){
            st.insert(it);
            x=it;
        }
        while(k<=x){
            if(st.find(res)!=st.end())res+=k;
            else return res;
        }
        return res;
    }
};