class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(n*m)

        // for(auto it:matrix){
        //     for(auto i:it)if(i==target)return true;
        // }
        // return false;

        //O(log(m*n)) -> binary search (consider matrix as an array by performing calculation to change the index of an array to a matrix or vice-versa)

        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int r=m*n-1;
        while(l<=r){
            //long long mid=(l+r)/2;
            int mid=(r-l)/2+l; // safe for overflow case
            int i=mid/m;
            int j=mid%m;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                l=mid+1;
            }else{
                //r=mid; //if l<r not l<=r
                r=mid-1;
            }
        }
        //return matrix[l/m][l%m]==target;
        return false;
    }
};