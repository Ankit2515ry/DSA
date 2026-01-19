class Solution {
public:
    bool check(vector<vector<int>>& grid,int i,int j,int k,int l){
        //if ((k - i) != (l - j)) return false;
        unordered_set<int>st;
        for(int x=i;x<=k;x++){
            int sum=0;
            for(int y=j;y<=l;y++){
                sum+=grid[x][y];
            }
            st.insert(sum);
        }
        for(int y=j;y<=l;y++){
            int sum=0;
            for(int x=i;x<=k;x++){
                sum+=grid[x][y];
            }
            st.insert(sum);
        }
        int x=i;
        int y=j;
        int sum=0;
        while(x<=k&&y<=l){
            sum+=grid[x][y];
            x++;
            y++;
        }
        st.insert(sum);
        x=k;
        y=j;
        sum=0;
        while(x>=i&&y<=l){
            sum+=grid[x][y];
            x--;
            y++;
        }
        st.insert(sum);
        if(st.size()==1)return true;
        return false;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=i;
                int l=j;
                while(k<n&&l<m){
                    if(check(grid,i,j,k,l)){
                        res=max(res,k-i+1);
                    }
                    k++;
                    l++;
                }
            }
        }
        return res;
    }
};