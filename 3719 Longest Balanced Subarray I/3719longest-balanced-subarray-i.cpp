class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>est;
            unordered_set<int>ost;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)est.insert(nums[j]);
                else ost.insert(nums[j]);
                if(est.size()==ost.size())res=max(res,j-i+1);
            }
        }
        return res;
    }
};