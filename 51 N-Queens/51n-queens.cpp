class Solution {
public:
    vector<vector<string>>res;
    bool check(vector<string>&board , int row ,int col){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')return false;
        }
        int m=min(row,col);
        for(int i=1;i<=m;i++){
            if(board[row-i][col-i]=='Q')return false;
        }
        m=min(row,(int)board.size()-col-1);
        for(int i=1;i<=m;i++){
            if(board[row-i][col+i]=='Q')return false;
        }
        return true;
    }
    void recursion(vector<string>&board , int row){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        for(int col=0;col<board.size();col++){
            if(check(board,row,col)){
                board[row][col]='Q';
                recursion(board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        recursion(board,0);
        return res;
    }
};