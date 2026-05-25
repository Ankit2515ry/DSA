class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //O(n2) space and time complexity

        // vector<vector<int>>temp=matrix;
        // int n=matrix.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         temp[j][n-i-1]=matrix[i][j];
        //     }
        // }
        // matrix=temp;
        
        // In place (transpose + reverse row)
        
        //transpose 
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

        

        //for 180 degree rotation
        //1-> reverse rows
        //2-> reverse matrix

        //for 90 degree anti-clockwise
        //1-> transpose 
        //2-> reverse column
        
    }
};