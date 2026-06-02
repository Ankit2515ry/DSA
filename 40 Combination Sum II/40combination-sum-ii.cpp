class Solution {
public:
    int t=0;
    set<vector<int>>st;
    void solve(vector<int>&c,int idx,int sum,vector<int>&temp){
        //tle
        // if(sum>=t||idx>=c.size()){
        //     if(sum==t){
        //         sort(temp.begin(),temp.end());
        //         st.insert(temp);
        //     }
        //     return;
        // }
        
        // solve(c,idx+1,sum,temp);
        // temp.push_back(c[idx]);
        // solve(c,idx+1,sum+c[idx],temp);
        // temp.pop_back();
        if(sum==t){
            st.insert(temp);
            return;
        }
        if(sum>t) return;
        for(int i=idx;i<c.size();i++){
            if(i>idx&&c[i-1]==c[i])continue;
            sum+=c[i];
            if(sum>t)break;
            temp.push_back(c[i]);
            solve(c,i+1,sum,temp);
            temp.pop_back();
            sum-=c[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        t=target;
        vector<int>temp;
        solve(candidates,0,0,temp);
        vector<vector<int>>res;
        for(auto it:st)res.push_back(it);
        return res;
    }
};