class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0)); 
        // vector<int> res;
        // int i = 0, j = 0;
        // char c = 'r'; 
        // for (int cnt = 0; cnt < n * m; cnt++) {
        //     res.push_back(matrix[i][j]);
        //     vis[i][j] = 1;
        //     if (c == 'r') {
        //         if (j + 1 < m && !vis[i][j + 1]) j++;
        //         else { c = 'd'; i++; }
        //     } 
        //     else if (c == 'd') {
        //         if (i + 1 < n && !vis[i + 1][j]) i++;
        //         else { c = 'l'; j--; }
        //     } 
        //     else if (c == 'l') {
        //         if (j - 1 >= 0 && !vis[i][j - 1]) j--;
        //         else { c = 'u'; i--; }
        //     } 
        //     else if (c == 'u') {
        //         if (i - 1 >= 0 && !vis[i - 1][j]) i--;
        //         else { c = 'r'; j++; }
        //     }
        // }  
        // return res;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};
