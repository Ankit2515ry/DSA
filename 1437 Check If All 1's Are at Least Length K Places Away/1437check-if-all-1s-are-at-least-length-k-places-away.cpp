class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        bool f=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1&&!f){
                f=true;
            }else if(f&&nums[i]==0){
                c++;
            }else if(nums[i]==1){
                if(c<k)return false;
                c=0;
            }
        }
        return true;
    }
};