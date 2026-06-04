class Solution {
public:
    vector<pair<int,int>>idx;
    bool isValid(vector<vector<char>>& b, int row, int col, char ch) {
        for(int j = 0; j < 9; j++) 
            if(b[row][j] == ch) return false;
        for(int i = 0; i < 9; i++) 
            if(b[i][col] == ch) return false;
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(b[startRow + i][startCol + j] == ch) return false;
            }
        }
        return true;
    }
    // bool valid(vector<vector<char>>& b) {
    //     int n=b.size();
    //     int m=b[0].size();
    //     for(int i=0;i<n;i++){
    //         unordered_set<char>st;
    //         for(int j=0;j<m;j++){
    //             if(st.find(b[i][j])!=st.end())return false;
    //             if(b[i][j]!='.')st.insert(b[i][j]);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         unordered_set<char>st;
    //         for(int j=0;j<m;j++){
    //             if(st.find(b[j][i])!=st.end())return false;
    //             if(b[j][i]!='.')st.insert(b[j][i]);
    //         }
    //     }
    //     vector<pair<int,int>>idx={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
    //     n=idx.size();
    //     for(int i=0;i<n;i++){
    //         int l=idx[i].first;
    //         int m=idx[i].second;
    //         unordered_set<char>st;
    //         for(int c=l;c<l+3;c++){
    //             for(int d=m;d<m+3;d++){
    //                 if(st.find(b[c][d])!=st.end())return false;
    //                 if(b[c][d]!='.')st.insert(b[c][d]);
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool solve(vector<vector<char>>&b,int ind){
        if(ind==idx.size())return true;
        int i=idx[ind].first;
        int j=idx[ind].second;
        //b[i][j]='1';
        char ch='1';
        while(ch<='9'){
            if(isValid(b,i,j,ch)){
                b[i][j]=ch;
                if(solve(b,ind+1))return true;
            }
            // if(valid(b)){
            //     if(solve(b,ind+1))return true;
            // }
            //b[i][j]++;
            ch++;
        }
        b[i][j] = '.';
        return false;
        // if(ind == idx.size()) return true;  
        // int i = idx[ind].first;
        // int j = idx[ind].second;
        // for(char c='1'; c<='9'; c++) {
        //     b[i][j] = c;
        //     if(valid(b)) {
        //         if(solve(b, ind+1)) return true;
        //     }
        //     b[i][j] = '.';
        // }
        // return false;
    }
    void solveSudoku(vector<vector<char>>& b) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='.')idx.push_back({i,j});
            }
        }
        solve(b,0);
    }
};