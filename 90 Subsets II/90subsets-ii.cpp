class Solution {
public:
    set<vector<int>>st;
    int n=0;
    void solve(vector<int>&nums,int idx,vector<int>temp){
        if(idx>=n){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        solve(nums,idx+1,temp);
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(nums,0,temp);
        vector<vector<int>>res;
        for(auto it:st)res.push_back(it);
        return res;
        // int n=nums.size();
        // set<vector<int>>st;
        // int x=1<<n;
        // for(int i=0;i<x;i++){
        //     vector<int>temp;
        //     for(int j=0;j<n;j++){
        //         if(i&1<<j){
        //             temp.push_back(nums[j]);
        //         }
        //     }
        //     sort(temp.begin(),temp.end());
        //     st.insert(temp);
        // }
        // vector<vector<int>>res;
        // for(auto it:st)res.push_back(it);
        // return res;
    }
};