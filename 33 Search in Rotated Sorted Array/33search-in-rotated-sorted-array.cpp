class Solution {
public:
    int search(vector<int>& nums, int target) {
        //O(n) time complexity
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target)return i;
        // }
        // return -1;

        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid=(r-l)/2+l;
        while(l<=r){
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid]){
                if(target<nums[mid]&&target>=nums[l]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(target>nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            mid=(r-l)/2+l;
        }
        return -1;
    }
};