class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n-2);
        for(int i=2;i<n;i++){
            for(int j=2;j<m;j++){
                int temp=INT_MIN;
                for(int x=i-2;x<=i;x++){
                    for(int y=j-2;y<=j;y++){
                        temp=max(temp,grid[x][y]);
                    }
                }
                res[i-2].push_back(temp);
            }
        }
        return res;
    }
};