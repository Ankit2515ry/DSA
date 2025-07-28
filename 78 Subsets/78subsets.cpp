class Solution {
public:
    // vector<vector<int>>subset;
    // void sub(int i,int n,vector<int>&temp,vector<int>&nums){
    //     if(i==n){
    //         subset.push_back(temp);
    //         return;
    //     }
    //     sub(i+1,n,temp,nums);
    //     temp.push_back(nums[i]);
    //     sub(i+1,n,temp,nums);
    //     temp.pop_back();
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsetCount=1<<n;
        vector<vector<int>>subset;
        for(int i=0;i<subsetCount;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i&1<<j)temp.push_back(nums[j]);
            }
            subset.push_back(temp);
        }
        return subset;
        // int n=nums.size();
        // vector<int>temp;
        // sub(0,n,temp,nums);
        // return subset;
    }
};