class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        int x=1<<n;
        for(int i=0;i<x;i++){
            int temp=0;
            for(int j=0;j<n-1;j++){
                temp|=((i>>j&1)^(i>>j+1&1))<<j;
            }
            temp|=(i>>n-1&1)<<n-1;
            res.push_back(temp);
        }
        return res;
    }
};