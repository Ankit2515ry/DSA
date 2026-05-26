class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //O(nlog(n))

        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n/2];

        //O(n) space and time complexity
        
        // int n=nums.size();
        // int m=n/2;
        // unordered_map<int,int>mp;
        // for(auto it:nums){
        //     mp[it]++;
        //     if(mp.count(it)){
        //         if(mp[it]>m)return it;
        //     }
        // }
        // return -1;

        //Moore Voting 
        //O(n) time and constant space complexity

        int res=0;
        int c=0;
        for(auto it:nums){
            if(c==0){
                res=it;
            }
            if(it==res)c++;
            else c--;
        }
        return res;

    }
};