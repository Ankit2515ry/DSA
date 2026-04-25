class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int m=q.size();
        int k=nums[0].size();
        vector<int>res(m,0);
        for(int i=0;i<m;i++){
            vector<pair<string,int>>temp;
            int ind=q[i][0];
            int t=q[i][1];
            for(int j=0;j<n;j++){
                temp.push_back({nums[j].substr(k-t),j});
            }
            // for(auto it:temp)cout<<it.first<<" ";
            // cout<<endl;
            sort(temp.begin(),temp.end());
            res[i]=temp[ind-1].second;
        }
        return res;
    }
};