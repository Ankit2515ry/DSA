class Solution {
public:
    int earliestTime(vector<vector<int>>& t) {
        int res=INT_MAX;
        int n=t.size();
        for(int i=0;i<n;i++){
            res=min(res,t[i][0]+t[i][1]);
        }
        return res;
    }
};