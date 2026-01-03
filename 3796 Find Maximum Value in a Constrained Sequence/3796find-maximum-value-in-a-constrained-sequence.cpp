class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        const int inf=1e9;
        vector<int>temp(n,inf);
        temp[0]=0;
        for(auto &it:restrictions){
            int i=it[0];
            int v=it[1];
            temp[i]=min(temp[i],v);
        }
        for(int i=0;i<n-1;i++){
            temp[i+1]=min(temp[i+1],temp[i]+diff[i]);
        }
        for(int i=n-2;i>=0;i--){
            temp[i]=min(temp[i],temp[i+1]+diff[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,temp[i]);
        }
        return res;
    }
};