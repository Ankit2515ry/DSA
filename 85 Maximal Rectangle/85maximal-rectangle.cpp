class Solution {
public:
    int res=0;
    void solve(int i,vector<vector<int>>& his){
        for(int k=0;k<his[i].size();k++){
            int mini=INT_MAX;
            for(int j=k;j<his[i].size();j++){
                mini=min(mini,his[i][j]);
                res=max(res,mini*(j-k+1));
            }
        }
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>his(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(mat[i][j]=='1'){
                    c++;
                    his[i][j]=c;
                }else{
                    c=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            solve(i,his);
        }
        return res;
    }
};