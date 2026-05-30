class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //O(n) time complexity;
        int n=nums.size();
        int j=1;
        int i=1;
        while(i<n){
            while(i<n&&nums[i]==nums[i-1])i++;
            if(i<n){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};