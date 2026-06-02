class Solution {
public:
    int t=0;
    set<vector<int>>st;
    void solve(vector<int>&c,int idx,int sum,vector<int>temp){
        if(sum>=t||idx>=c.size()){
            if(sum==t){
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            return;
        }
        solve(c,idx+1,sum,temp);
        sum+=c[idx];
        temp.push_back(c[idx]);
        solve(c,idx,sum,temp);
        solve(c,idx+1,sum,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t=target;
        vector<int>temp;
        solve(candidates,0,0,temp);
        vector<vector<int>>res;
        for(auto it:st)res.push_back(it);
        return res;
    }
};