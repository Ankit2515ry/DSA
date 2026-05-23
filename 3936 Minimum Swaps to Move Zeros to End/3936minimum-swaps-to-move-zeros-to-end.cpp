class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(auto it:nums)if(it==0)c++;
        int i=n-1;
        int x=c;
        while(i>=0&&x>0){
            if(nums[i]==0){
                c--;
            }
            i--;
            x--;
        }
        return c;
    }
};