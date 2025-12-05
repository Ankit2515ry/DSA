class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int dif=INT_MAX;
        int res=INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<dif){
                    res=sum;
                    dif=abs(sum-target);
                }
                if(sum<target)l++;
                else if(sum>target)r--;
                else return sum;
            }
        }
        return res;
    }
};