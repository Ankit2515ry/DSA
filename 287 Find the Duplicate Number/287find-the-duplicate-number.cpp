class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //bruteforce O(n2) time complexity constant time

        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j])return nums[i];
        //     }
        // }
        // return -1;

        //modifing input O(nlog(n))

        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1])return nums[i];
        // }
        // return -1;

        //using set or visited vector O(n) space and time complexity

        // unordered_set<int>st;
        // for(auto it:nums){
        //     if(st.count(it))return it;
        //     st.insert(it);
        // }
        // return -1;

        //Tortoise and Hare Algorithm (Floyd’s Cycle Detection Algorithm)

        int n=nums.size();
        int s=nums[0];
        int f=nums[0];
        //find cycle
        do{
            s=nums[s];
            f=nums[nums[f]];
        }while(s!=f);
        s=nums[0];
        //find enterence point
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }
        return s;

    }
};