class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {   
        //     bool f = true;
        //     bool first = true;        
        //     int pre = 0;             
        //     for (int j = 0; j < n; j++) {
        //         if (j == i) continue; 
        //         //for handling first pre    
        //         if (first) {         
        //             pre = nums[j];
        //             first = false;
        //         } else {
        //             if (nums[j] < pre) {
        //                 f = false;   
        //                 break;         
        //             }
        //             pre = nums[j];     
        //         }
        //     }
        //     if (f) return true;        
        // }
        // return false;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(i+1<n&&nums[i]>nums[i+1]){
                count++;
                if(count>1)return false;
                if(i-1>=0&&nums[i-1]>nums[i+1]){
                    if(i+2<n&&nums[i]>nums[i+2])return false;
                }
            }
        }
        return true;
    }
};
