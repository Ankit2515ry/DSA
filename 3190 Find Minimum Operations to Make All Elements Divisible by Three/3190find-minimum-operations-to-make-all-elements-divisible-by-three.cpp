class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=0;
        for(auto &it:nums){
            if(it%3!=0)res++;
        }
        return res;
    }
};