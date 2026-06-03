class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        vector<vector<int>>res;
        res.push_back(temp);
        while(next_permutation(temp.begin(),temp.end())){
            res.push_back(temp);
        }
        return res;
    }
};