class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool in=false;
        bool mi=false;
        bool en=false;
        int p=0;
        int q=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                in = true;
                p=i+1;
            }else break;
        }
        for(int i=p;p>=1&&i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                mi = true;
                q=i+1;
            }else break;
        }
        for(int i=q;q>=p+1&&i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                en = true;
            }else {
                en=false;
                break;
            }
        }
        return (in&&mi&&en);
    }
};